/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_args_echo_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 12:15:41 by dtanski           #+#    #+#             */
/*   Updated: 2025/02/19 23:18:07 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*join_vars(t_token **token_node)
{
	t_token	*tmp;
	char	*str;

	tmp = *token_node;
	str = ft_strdup(tmp->str);
	while (tmp->type == VAR && tmp->next->type == VAR
		&& tmp->next->join == true)
	{
		str = ft_strjoin(str, tmp->next->str);
		tmp = tmp->next;
	}
	*token_node = tmp;
	return (str);
}

int	count_args(t_token *tmp)
{
	int	i;

	i = 0;
	while (tmp && (tmp->type == WORD || tmp->type == VAR))
	{
		if (tmp->type == VAR && tmp->join == true)
		{
			while (tmp->type == VAR && tmp->join == true)
				tmp = tmp->next;
			i++;
		}
		else
		{
			i++;
			tmp = tmp->next;
		}
	}
	return (i);
}

char	**copy_in_new_tab(int len, char **new_tab,
	t_command *last_cmd, t_token *tmp)
{
	int	i;

	i = 0;
	while (i < len)
	{
		new_tab[i] = last_cmd->args[i];
		i++;
	}
	while (tmp->type == WORD || tmp->type == VAR)
	{
		if (tmp->join == true)
			new_tab[i] = join_vars(&tmp);
		else
			new_tab[i] = ft_strdup(tmp->str);
		i++;
		tmp = tmp->next;
	}
	new_tab[i] = NULL;
	return (new_tab);
}

void	remove_empty_var_args(t_token **tokens)
{
	t_token	*tmp;

	tmp = *tokens;
	while (tmp->type == WORD || tmp->type == VAR)
	{
		if (tmp->type == VAR && tmp->str[0] == '\0' && tmp->var_exists == false)
		{
			tmp = tmp->next;
			if (tmp == (*tokens)->next)
				(*tokens) = (*tokens)->next;
			lstdelone_token(tmp->prev, free_ptr);
		}
		else
			tmp = tmp->next;
	}
}
