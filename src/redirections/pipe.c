/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:44:16 by pjedrycz          #+#    #+#             */
/*   Updated: 2024/12/05 21:47:07 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Closes the pipe fds of all commands. A pointer to a command to skip
// can be specified to skip closing that command's pipe fds:
// -- The parent will specify NULL for the skip command while closing
// 	all pipe fds.
// -- The child will specify its own command as skip command while
// 	closing all pipe fds so as to not accidentally close its own
// 	pipe fds.
void	close_pipe_fds(t_command *cmds, t_command *skip_cmd)
{
	while (cmds)
	{
		if (cmds != skip_cmd && cmds->pipe_fd)
		{
			close(cmds->pipe_fd[0]);
			close(cmds->pipe_fd[1]);
		}
		cmds = cmds->next;
	}
}

// Creates all the needed pipes for all the commands.
// 1 for success and 0 for fail.
bool	create_pipes(t_data *data)
{
	int			*fd;
	t_command	*tmp;

	tmp = data->cmd;
	while (tmp)
	{
		if (tmp->pipe_output || (tmp->prev && tmp->prev->pipe_output))
		{
			fd = malloc(sizeof * fd * 2);
			if (!fd || pipe(fd) != 0)
			{
				free_data(data, false);
				return (false);
			}
			tmp->pipe_fd = fd;
		}
		tmp = tmp->next;
	}
	return (true);
}

// Sets the pipe fds for this command. If the previous command
// was piped to this one, sets the input as the read end of
// the previous command. If this command is piped to the
// next, sets the output ad the write end of the pipe.
// --	pipe_fd[0] = read end of pipe.
// --	pipe_fd[1] = write end of pipe.
// Returns true when the pipe file descriptors are set.
bool	set_pipe_fds(t_command *cmds, t_command *c)
{
	if (!c)
		return (false);
	if (c->prev && c->prev->pipe_output)
		dup2(c->prev->pipe_fd[0], STDIN_FILENO);
	if (c->pipe_output)
		dup2(c->pipe_fd[1], STDOUT_FILENO);
	close_pipe_fds(cmds, c);
	return (true);
}
