/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:25:13 by pjedrycz          #+#    #+#             */
/*   Updated: 2025/02/19 23:07:30 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Interactive signal handling - resets for the new, 
// clean line in the terminal.
static void	signal_reset_prompt(int signo)
{
	(void)signo;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

// Replaces SIGQUIT signals (ctrl-\) with SIG_IGN to ignore
// the signal.
void	ignore_sigquit(void)
{
	struct sigaction	act;

	ft_memset(&act, 0, sizeof(act));
	act.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &act, NULL);
}

// For interactive mode. Sets handling way for signals (ctr+c, ctrl+\).
// SIGINT - sets new clean line.
// SIGQUIT - ingored
void	set_signals_interactive(void)
{
	struct sigaction	act;

	ignore_sigquit();
	ft_memset(&act, 0, sizeof(act));
	act.sa_handler = &signal_reset_prompt;
	sigaction(SIGINT, &act, NULL);
}

// For noninteractive mode.
// Prints a newline.
static void	signal_print_newline(int signal)
{
	(void)signal;
	rl_on_new_line();
}

// For noninteractive mode. Sets handling way for signals (ctr+c, ctrl+\).
// Means that while command is running, program 
// won't react for SIGQUIT and SIGINT signals.
void	set_signals_noninteractive(void)
{
	struct sigaction	act;

	ft_memset(&act, 0, sizeof(act));
	act.sa_handler = &signal_print_newline;
	sigaction(SIGINT, &act, NULL);
	sigaction(SIGQUIT, &act, NULL);
}
