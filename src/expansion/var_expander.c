/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_expander.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 20:50:53 by dtanski           #+#    #+#             */
/*   Updated: 2025/03/03 22:21:36 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static void	update_status(t_token **token_node, char c)
{
	if (c == '\'' && (*token_node)->status == DEFAULT)
		(*token_node)->status = SQUOTE;
	else if (c == '\"' && (*token_node)->status == DEFAULT)
		(*token_node)->status = DQUOTE;
	else if (c == '\'' && (*token_node)->status == SQUOTE)
		(*token_node)->status = DEFAULT;
	else if (c == '\"' && (*token_node)->status == DQUOTE)
		(*token_node)->status = DEFAULT;
}

static bool	is_next_char_a_sep(char c)
{
	if (c == '$' || c == ' ' || c == '=' || c == '\0')
		return (true);
	else
		return (false);
}

static bool	var_sign_between_quotes(char *str, int i)
{
	if (i > 0)
	{
		if (str[i - 1] == '\"' && str[i + 1] == '\"')
			return (true);
		else
			return (false);
	}
	return (false);
}

int	var_expander(t_data *data, t_token **token_list)
{
	t_token	*tmp;
	int		i;

	tmp = *token_list;
	while (tmp)
	{
		if (tmp->type == VAR)
		{
			i = 0;
			while (tmp->str[i])
			{
				update_status(&tmp, tmp->str[i]);
				if (tmp->str[i] == '$' && is_next_char_a_sep(tmp->str[i + 1])
					== false && var_sign_between_quotes(tmp->str, i)
					== false && (tmp->status == DEFAULT
						|| tmp->status == DQUOTE))
					replace_var(&tmp, recover_val(tmp, tmp->str + i, data), i);
				else
					i++;
			}
		}
		tmp = tmp->next;
	}
	return (0);
}

char	*var_expander_heredoc(t_data *data, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$'
			&& is_next_char_a_sep(str[i + 1]) == false
			&& data->token->status == DQUOTE
			&& var_sign_between_quotes(str, i) == false)
			str = replace_str_heredoc(str, recover_val(NULL, str + i, data), i);
		else
			i++;
	}
	return (str);
}
