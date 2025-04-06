/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:31:55 by pjedrycz          #+#    #+#             */
/*   Updated: 2025/03/07 19:03:40 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Executes the given command if it is a builtin command.
// Returns -1 if the command is not a builtin command.
// Returns 0 or 1 if the builtin command succeeded or failed.
int	execute_builtin(t_data *data, t_command *cmd)
{
	int	ret;

	ret = CMD_NOT_FOUND;
	if (ft_strncmp(cmd->cmd, "cd", 3) == 0)
		ret = cd_builtin(data, cmd->args);
	else if (ft_strncmp(cmd->cmd, "echo", 5) == 0)
		ret = echo_builtin(data, cmd->args);
	else if (ft_strncmp(cmd->cmd, "env", 4) == 0)
		ret = env_builtin(data, cmd->args);
	else if (ft_strncmp(cmd->cmd, "export", 7) == 0)
		ret = export_builtin(data, cmd->args);
	else if (ft_strncmp(cmd->cmd, "pwd", 4) == 0)
		ret = pwd_builtin(data, cmd->args);
	else if (ft_strncmp(cmd->cmd, "unset", 6) == 0)
		ret = unset_builtin(data, cmd->args);
	else if (ft_strncmp(cmd->cmd, "exit", 5) == 0)
		ret = exit_builtin(data, cmd->args);
	return (ret);
}

// Executes the command's system binary file if it can be found
// among the environment executable paths.
// Returns CMD_NOT_FOUND if a path to the executable bin file cannot be
// found. Returns 1 in case of failure to run existing, executable
// file.
static int	execute_sys_bin(t_data *data, t_command *cmd)
{
	if (!cmd->cmd || cmd->cmd[0] == '\0')
		return (CMD_NOT_FOUND);
	if (cmd_is_dir(cmd->cmd))
		return (CMD_NOT_FOUND);
	cmd->path = get_cmd_path(data, cmd->cmd);
	if (!cmd->path)
		return (CMD_NOT_FOUND);
	if (execve(cmd->path, cmd->args, data->env) == -1)
		errmsg_cmd("execve", NULL, strerror(errno), errno);
	return (EXIT_FAILURE);
}

// Attempts to execute the given command as is, in case
// it is a local directory file or already contains the
// path to bin.
// Returns CMD_NOT_FOUND if the command is not an existing executable
// file. Returns 1 in case of failure to launch executable.
static int	execute_local_bin(t_data *data, t_command *cmd)
{
	int	ret;

	ret = check_cmmd_not_found(data, cmd);
	if (ret != 0)
		return (ret);
	if (execve(cmd->cmd, cmd->args, data->env) == -1)
		return (errmsg_cmd("execve", NULL, strerror(errno), errno));
	return (EXIT_FAILURE);
}

// When child process will try to execute the command,
// it'll set its in/out fds and search for executable
// in this order:
// 	1. Execute builtin command
// 	2. Execute system binaries for command.
// 	3. Execute given command name directly (local bin)
// If it cannot find a matching builtin or executable,
// prints an error message.
// Child exits with it's executed program's exit code, or 1 if
// it could not find one.
int	execute_command(t_data *data, t_command *cmd)
{
	int	ret;

	if (!cmd || !cmd->cmd)
		exit_shell(data, errmsg_cmd("child", NULL,
				"parsing error: no command to execute",
				EXIT_FAILURE));
	if (!check_infile_outfile(cmd->io_fds))
		exit_shell(data, EXIT_FAILURE);
	set_pipe_fds(data->cmd, cmd);
	redirect_io(cmd->io_fds);
	close_fds(data->cmd, false);
	if (ft_strchr(cmd->cmd, '/') == NULL)
	{
		ret = execute_builtin(data, cmd);
		if (ret != CMD_NOT_FOUND)
			exit_shell(data, ret);
		ret = execute_sys_bin(data, cmd);
		if (ret != CMD_NOT_FOUND)
			exit_shell(data, ret);
	}
	ret = execute_local_bin(data, cmd);
	exit_shell(data, ret);
	return (ret);
}
