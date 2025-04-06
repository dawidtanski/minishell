/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 09:28:45 by dtanski           #+#    #+#             */
/*   Updated: 2025/03/06 18:13:09 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	is_separator(char *str, int i)
{
	if (((str[i] > 8 && str[i] < 14) || str[i] == 32))
		return (SPACES);
	else if (str[i] == '|')
		return (PIPE);
	else if (str[i] == '<' && str[i + 1] && str[i + 1] == '<')
		return (HEREDOC);
	else if (str[i] == '>' && str[i + 1] && str[i + 1] == '>')
		return (APPEND);
	else if (str[i] == '<')
		return (INPUT);
	else if (str[i] == '>')
		return (TRUNC);
	else if (str[i] == '\0')
		return (END);
	else
		return (WORD);
}

void	copy_str(char *src, char *dest, int i, int j)
{
	int	k;

	k = 0;
	while (i < j)
		dest[k++] = src[i++];
	dest[k] = '\0';
}

void	skip_spaces(char *input, int *i)
{
	while (input[*i] && ft_isspace(input[*i]))
		(*i)++;
}

int	set_type_and_status(char *input, int *i, int *s)
{
	int	type;

	type = is_separator(input, *i);
	*s = set_status(*i, input, *s);
	return (type);
}
