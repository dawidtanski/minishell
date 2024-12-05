/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_io.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:28:26 by pjedrycz          #+#    #+#             */
/*   Updated: 2024/12/05 21:35:07 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// After finish run the program - restores sdin & stdout
// to their original values (fd of 0 and 1).
// It's needed before next usage of minishell program. 
// 1 for successfull operation and 0 for fail.
bool	restore_io(t_io_fds *io)
{
	int	ret;

	ret = true;
	if (!io)
		return (ret);
	if (io->stdin_backup != -1)
	{
		if (dup2(io->stdin_backup, STDIN_FILENO) == -1)
			ret = false;
		close(io->stdin_backup);
		io->stdin_backup = -1;
	}
	if (io->stdout_backup != -1)
	{
		if (dup2(io->stdout_backup, STDOUT_FILENO) == -1)
			ret = false;
		close(io->stdout_backup);
		io->stdout_backup = -1;
	}
	return (ret);
}

// Duplicates the input and output fds to the standard input and output.
// Backs up the standard input and output before replacing them in order
// to restore them after execution.
// Returns 1 for success, 0 in case of error.
bool	redirect_io(t_io_fds *io)
{
	int	ret;

	ret = true;
	if (!io)
		return (ret);
	io->stdin_backup = dup(STDIN_FILENO);
	if (io->stdin_backup == -1)
		ret = errmsg_cmd("dup", "stdin_backup", strerror(errno), false);
	io->stdout_backup = dup(STDOUT_FILENO);
	if (io->stdout_backup == -1)
		ret = errmsg_cmd("dup", "stdout_backup", strerror(errno), false);
	if (io->fd_in != -1)
		if (dup2(io->fd_in, STDIN_FILENO) == -1)
			ret = errmsg_cmd("dup2", io->infile, strerror(errno), false);
	if (io->fd_out != -1)
		if (dup2(io->fd_out, STDOUT_FILENO) == -1)
			ret = errmsg_cmd("dup2", io->outfile, strerror(errno), false);
	return (ret);
}

// Check if outfile and infile are correct.
// 1 for success and 0 for fail.
bool	check_infile_outfile(t_io_fds *io)
{
	if (!io || (!io->infile && !io->outfile))
		return (true);
	if ((io->infile && io->fd_in == -1)
		|| (io->outfile && io->fd_out == -1))
		return (false);
	return (true);
}
