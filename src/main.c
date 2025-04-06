/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 22:15:50 by pjedrycz          #+#    #+#             */
/*   Updated: 2025/02/19 21:44:12 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Cheks if program can start properly.
// We can stats if:
// -- without any arguments,
// -- with one argument as a "-c" option.
// True if program can start and false if it can't
static bool	start_check(t_data *data, int argc, char **argv)
{
	if (argc != 1 && argc != 3)
		return (usage_message(false));
	if (argc == 3)
	{
		data->interactive = false;
		if (!argv[1] || (argv[1] && ft_strcmp(argv[1], "-c") != 0))
			return (usage_message(false));
		else if (!argv[2] || (argv[2] && argv[2][0] == '\0'))
			return (usage_message(false));
	}
	else
		data->interactive = true;
	return (true);
}

// When starts without any arguments, runs parsing and execution 
// as for interactive mode.
// Provides prompt for use input.
void	minishell_interactive(t_data *data)
{
	while (1)
	{
		set_signals_interactive();
		data->usr_input = readline(PROMPT);
		set_signals_noninteractive();
		if (parse_user_input(data) == true)
			g_last_exit_code = execute(data);
		else
			g_last_exit_code = 1;
		free_data(data, false);
	}
}

void	minishell_noninteractive(t_data *data, char *arg)
{
	char	**usr_inputs;
	int		i;

	usr_inputs = ft_split(arg, ';');
	if (!usr_inputs)
		exit_shell(data, EXIT_FAILURE);
	i = 0;
	while (usr_inputs[i])
	{
		data->usr_input = ft_strdup(usr_inputs[i]);
		if (parse_user_input(data) == true)
			g_last_exit_code = 1;
		i++;
		free_data(data, false);
	}
	free_str_tab(usr_inputs);
}

// All fun begins here.

// Checking input and decides if program shoud run in
// interactive or not interactive mode.

// Exits program with exit status or last command
int	main(int argc, char **argv, char **env)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(t_data));
	if (!start_check(&data, argc, argv) || !init_data(&data, env))
		exit_shell(NULL, EXIT_FAILURE);
	if (data.interactive)
		minishell_interactive(&data);
	else
		minishell_noninteractive(&data, argv[2]);
	exit_shell(&data, g_last_exit_code);
	return (0);
}
