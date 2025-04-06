/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_user_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:15:27 by dtanski           #+#    #+#             */
/*   Updated: 2025/02/26 19:15:53 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// enum e_token_types {
// 	SPACES = 1,
// 	WORD,
// 	VAR,
// 	PIPE,
// 	INPUT,
// 	TRUNC,
// 	HEREDOC,
// 	APPEND,
// 	END
// };

static bool	consecutive_ops(t_token *token_node)
{
	if (token_node->prev)
	{
		if (token_node->type == PIPE && token_node->prev->type == PIPE)
			return (true);
		if (token_node->type > PIPE && token_node->prev->type > PIPE)
			return (true);
		if (token_node->type == END && token_node->prev->type >= PIPE)
			return (true);
	}
	return (false);
}

int	check_consecutives(t_token **token_lst)
{
	t_token	*temp;

	temp = *token_lst;
	while (temp)
	{
		if (consecutive_ops(temp) == true)
		{
			if (temp->type == END && temp->prev && temp->prev->type > PIPE)
				errmsg("syntax error near unexpected token", "newline", true);
			else if (temp->type == END && temp->prev)
				errmsg("syntax error near unexpected token",
					temp->prev->str, true);
			else
				errmsg("syntax error near unexpected token", temp->str, true);
			return (FAILURE);
		}
		temp = temp->next;
	}
	return (SUCCESS);
}

static void	variable_check(t_token **token_node)
{
	int	i;

	i = 0;
	while ((*token_node)->str[i])
	{
		if ((*token_node)->str[i] == '$')
		{
			if ((*token_node)->prev && (*token_node)->prev->type == HEREDOC)
				break ;
			(*token_node)->type = VAR;
			return ;
		}
		i++;
	}
}

int	check_if_var(t_token **token_lst)
{
	t_token	*tmp;

	tmp = *token_lst;
	if (tmp->type == PIPE)
	{
		errmsg("syntax error near unexpected token", tmp->str, true);
		return (FAILURE);
	}
	while (tmp)
	{
		variable_check(&tmp);
		tmp = tmp->next;
	}
	return (SUCCESS);
}

bool	parse_user_input(t_data *data)
{
	if (data->usr_input == NULL)
		exit_builtin(data, NULL);
	else if (ft_strcmp(data->usr_input, "\0") == 0)
		return (false);
	else if (ft_strisspace(data->usr_input))
		return (true);
	add_history(data->usr_input);
	if (tokenizer(data->usr_input, data, 0, 0) == FAILURE)
		return (false);
	if (data->token->type == END)
		return (false);
	if (check_if_var(&data->token) == FAILURE)
		return (false);
	var_expander(data, &data->token);
	handle_quotes(data);
	create_commands(data, data->token);
	return (true);
}
