/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 09:28:45 by dtanski           #+#    #+#             */
/*   Updated: 2025/03/06 18:13:06 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	handle_quotes_tok(char *input, int *i, char **word_or_sep, int *status)
{
	char	quote;
	int		start;
	int		j;

	quote = input[*i];
	(*i)++;
	start = *i;
	j = *i;
	while (input[j] && input[j] != quote)
		j++;
	*word_or_sep = malloc(sizeof(char) * ((j - start) + 1));
	if (!*word_or_sep)
		return (FAILURE);
	copy_str(input, *word_or_sep, start, j);
	if (input[j] == quote)
		j++;
	*i = j;
	if (ft_isspace(input[*i]))
		*status = DEFAULT;
	else
		*status = set_status(input[*i], input, *status);
	return (SUCCESS);
}

int	handle_word(char *input, int *i, char **word_or_sep, int *status)
{
	int	start;
	int	j;

	start = *i;
	j = *i;
	while (input[j] && !ft_isspace(input[j]) && is_separator(input, j) == WORD)
	{
		*status = set_status(j, input, *status);
		j++;
	}
	*word_or_sep = malloc(sizeof(char) * ((j - start) + 1));
	if (!*word_or_sep)
		return (FAILURE);
	copy_str(input, *word_or_sep, start, j);
	*i = j;
	return (SUCCESS);
}
