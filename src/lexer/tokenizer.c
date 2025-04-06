/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanski <dtanski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 09:28:45 by dtanski           #+#    #+#             */
/*   Updated: 2025/03/07 19:36:53 by dtanski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	set_status(int i, char *input, int status)
{
	if (input[i] == '\'' && status == DEFAULT)
	{
		status = SQUOTE;
	}
	else if (input[i] == '\"' && status == DEFAULT)
	{
		status = DQUOTE;
	}
	else if (input[i] == '\'' && status == SQUOTE)
	{
		status = DEFAULT;
	}
	else if (input[i] == '\"' && status == DQUOTE)
	{
		status = DEFAULT;
	}
	return (status);
}

int	parse_operators(char *input, int *type, int *i, char **word_or_sep)
{
	int		len;

	len = 1;
	if ((*type == HEREDOC && input[*i + 1] == '<')
		|| (*type == APPEND && input[*i + 1] == '>'))
		len = 2;
	*word_or_sep = malloc(sizeof(char) * (len + 1));
	if (!*word_or_sep)
		return (FAILURE);
	copy_str(input, *word_or_sep, *i, *i + len);
	*i += len;
	return (SUCCESS);
}

int	parse_words(char *input, int *i, char **word_or_sep, int *status)
{
	if (input[*i] == '\"' || input[*i] == '\'')
		return (handle_quotes_tok(input, i, word_or_sep, status));
	else
		return (handle_word(input, i, word_or_sep, status));
}

int	tokenizer(char *input, t_data *data, int i, int s)
{
	char	*t;
	int		type;

	while (input[i])
	{
		skip_spaces(input, &i);
		if (!input[i])
			break ;
		type = set_type_and_status(input, &i, &s);
		if (type && type != SPACES && s == DEFAULT)
		{
			if (parse_operators(input, &type, &i, &t) == FAILURE)
				return (FAILURE);
			add_btk(&data->token, lst_ntkn(ft_strdup(t), NULL, type, s));
		}
		else
		{
			if (parse_words(input, &i, &t, &s) == FAILURE)
				return (FAILURE);
			add_btk(&data->token, lst_ntkn(ft_strdup(t), ft_strdup(t), 0, s));
		}
		free(t);
	}
	add_btk(&data->token, lst_ntkn(ft_strdup(""), NULL, END, 0));
	return (SUCCESS);
}
