/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:18:08 by pjedrycz          #+#    #+#             */
/*   Updated: 2024/12/05 21:55:30 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Joins two strings, frees an old one.
// Returns new string or NULL if failed.
static char	*join_strs(char *str, char *add)
{
	char	*tmp;

	if (!add)
		return (str);
	if (!str)
		return (ft_strdup(add));
	tmp = str;
	str = ft_strjoin(tmp, add);
	free_ptr(tmp);
	return (str);
}

// Checks whether to add quotes around the error detail:
// i.e. "unset: `@': not a valid identifier"
// Returns true if the command is export or unset,
// false if not.
static bool	add_detail_quotes(char *comm)
{
	if (ft_strncmp(comm, "export", 7) == 0
		|| ft_strncmp(comm, "unset", 6) == 0)
		return (true);
	return (false);
}

// Prints error message to standard error output. 
// Program name is added.
// Returns error number.
int	errmsg_cmd(char	*comm, char *detail, char *err_msg, int err_nb)
{
	char	*msg;
	bool	detail_quotes;

	detail_quotes = add_detail_quotes(comm);
	msg = ft_strdup("minishell: ");
	if (comm != NULL)
	{
		msg = join_strs(msg, comm);
		msg = join_strs(msg, ": ");
	}
	if (detail != NULL)
	{
		if (detail_quotes)
			msg = join_strs(msg, "`");
		msg = join_strs(msg, detail);
		if (detail_quotes)
			msg = join_strs(msg, "'");
		msg = join_strs(msg, ": ");
	}
	msg = join_strs(msg, err_msg);
	ft_putendl_fd(msg, STDERR_FILENO);
	free_ptr(msg);
	return (err_nb);
}

// Prints error message.
// Using in parsing module for error handling.
void	errmsg(char *errmsg, char *detail, int quotes)
{
	char	*msg;

	msg = ft_strdup("minishell: ");
	msg = join_strs(msg, errmsg);
	if (quotes)
		msg = join_strs(msg, " `");
	else
		msg = join_strs(msg, ": ");
	msg = join_strs(msg, detail);
	if (quotes)
		msg = join_strs(msg, "'");
	ft_putendl_fd(msg, STDERR_FILENO);
	free_ptr(msg);
}

// For start up check - prints usage message if arguments
// are not valid.
bool	usage_message(bool return_val)
{
	ft_putendl_fd("Usage: ./minishell", 2);
	ft_putendl_fd("Usage: ./minishell -c \"input line\"", 2);
	return (return_val);
}
