/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:02:25 by pjedrycz          #+#    #+#             */
/*   Updated: 2025/03/07 08:39:46 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Returns true if "exit" should not be preintet - quiet mode.
// Returns false if it should be printed - exit was called alone.
static bool	is_quiet_mode(t_data *data)
{
	t_command	*cmd;

	cmd = data->cmd;
	if (!cmd)
		return (false);
	if (cmd->next != NULL || cmd->prev != NULL)
		return (true);
	return (false);
}

// Checks if the number goes over LONG_MAX or LONG_MIN.
// Sets an error boolean to true if the number is out of range, false if not.
static bool	check_out_of_range(int neg, unsigned long long nb, bool *error)
{
	if ((neg == 1 && nb > LONG_MAX)
		|| (neg == -1 && nb > -(unsigned long)LONG_MIN))
		*error = true;
	return (*error);
}

// Transforms string into long int and returns it.
// If we have an error - sets error arg to true.
static int	ft_atoi_long(const char *nptr, bool *error)
{
	unsigned long long	nb;
	int					neg;
	int					i;

	nb = 0;
	neg = 1;
	i = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '+' && nptr[i + 1] != '-')
		i++;
	if (nptr[i] == '-')
	{
		neg = -1;
		i++;
	}
	while (nptr[i] && nptr[i] >= 48 && nptr[i] <= 57)
	{
		nb = (nb * 10) + (nptr[i] - 48);
		if (check_out_of_range(neg, nb, error))
			break ;
		i++;
	}
	return (nb * neg);
}

// Gets the exit code from the arguments given to the exit builtin.
// Returns 0 if no arguments were provided.
// Returns 2 in case argument is not digits.
// Returns the numeric exit code on success.
static int	get_exit_code(char *arg, bool *error)
{
	unsigned long long	i;

	if (!arg)
		return (g_last_exit_code);
	i = 0;
	while (ft_isspace(arg[i]))
		i++;
	if (arg[i] == '\0')
		*error = true;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	if (!ft_isdigit(arg[i]))
		*error = true;
	while (arg[i])
	{
		if (!isdigit(arg[i]) && !ft_isspace(arg[i]))
			*error = true;
		i++;
	}
	i = ft_atoi_long(arg, error);
	return (i % 256);
}

// Exit feature starts here.
// If alone, prints exit and exits the shell with the provided 
// exit code, or 0.
// If piped, exits the child process with the provided 
// exit code and does not exit
// minishell.
// In case of failure due to invalid arguments, does not exit the shell
// and returns an error exit code (1 or 2) instead.
int	exit_builtin(t_data *data, char **args)
{
	int		exit_code;
	bool	error;
	bool	quiet;

	quiet = is_quiet_mode(data);
	error = false;
	if (!quiet && data->interactive && isatty(STDIN_FILENO))
		ft_putendl_fd("exit", 2);
	if (!args || !args[1])
		exit_code = g_last_exit_code;
	else
	{
		exit_code = get_exit_code(args[1], &error);
		if (error)
			exit_code = errmsg_cmd("exit", args[1],
					"give me some numeric arg", 2);
		else if (args[2])
			return (errmsg_cmd("exit", NULL, "too many args", 1));
	}
	exit_shell(data, exit_code);
	return (2);
}
