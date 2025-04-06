/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:41:00 by dtanski           #+#    #+#             */
/*   Updated: 2025/03/05 22:17:21 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static bool	contains_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isspace(str[i]))
			return (true);
		i++;
	}
	return (false);
}

static void	split_var_cmd_token(t_command *last_cmd, char *cmd_str)
{
	t_token		*new_tokens;
	t_token		*tmp;
	char		**strs;
	int			i;

	new_tokens = NULL;
	strs = ft_split(cmd_str, ' ');
	if (!strs)
		return ;
	last_cmd->cmd = ft_strdup(strs[0]);
	if (strs[1])
		new_tokens = lst_ntkn(ft_strdup(strs[1]), NULL, WORD, DEFAULT);
	tmp = new_tokens;
	i = 1;
	while (strs[++i])
		add_btk(&new_tokens,
			lst_ntkn(ft_strdup(strs[i]), NULL, WORD, DEFAULT));
	add_btk(&new_tokens,
		lst_ntkn(NULL, NULL, END, DEFAULT));
	fill_args(&new_tokens, last_cmd);
	lstclear_token(&tmp, *free_ptr);
	free_str_tab(strs);
}

void	parse_word(t_command **cmd, t_token **token_lst)
{
	t_token		*tmp;
	t_command	*last_cmd;

	tmp = *token_lst;
	while (tmp->type == WORD || tmp->type == VAR)
	{
		last_cmd = lst_last_cmd(*cmd);
		if (tmp->prev == NULL || (tmp->prev && tmp->prev->type == PIPE)
			|| last_cmd->cmd == NULL)
		{
			if (tmp->type == VAR && contains_space(tmp->str))
				split_var_cmd_token(last_cmd, tmp->str);
			else
				last_cmd->cmd = ft_strdup(tmp->str);
			tmp = tmp->next;
		}
		else
			fill_args(&tmp, last_cmd);
	}
	*token_lst = tmp;
}
