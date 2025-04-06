/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 22:07:33 by pjedrycz          #+#    #+#             */
/*   Updated: 2025/03/03 21:53:38 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Checks if the command is a directory name.
// True if yes and false if it's executable.
bool	cmd_is_dir(char *cmd)
{
	struct stat	cmd_stat;

	ft_memset(&cmd_stat, 0, sizeof(cmd_stat));
	stat(cmd, &cmd_stat);
	return (S_ISDIR(cmd_stat.st_mode));
}

// Checks if given command is a valid one and is executable.
// If not, returns exact error of found reason.
// Returns EXIT_SUCCESS if the command was found and should
// be executed.
int	check_cmmd_not_found(t_data *data, t_command *cmd)
{
	if (ft_strchr(cmd->cmd, '/') == NULL
		&& get_env_var_index(data->env, "PATH") != -1)
		return (errmsg_cmd(cmd->cmd, NULL, "command not found",
				CMD_NOT_FOUND));
	if (access(cmd->cmd, F_OK) != 0)
		return (errmsg_cmd(cmd->cmd, NULL, strerror(errno),
				CMD_NOT_FOUND));
	else if (cmd_is_dir(cmd->cmd))
		return (errmsg_cmd(cmd->cmd, NULL, "Is a directory",
				CMD_NOT_EXECUTABLE));
	else if (access(cmd->cmd, F_OK || X_OK) != 0)
		return (errmsg_cmd(cmd->cmd, NULL, strerror(errno),
				CMD_NOT_EXECUTABLE));
	return (EXIT_SUCCESS);
}
