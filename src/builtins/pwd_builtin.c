/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 21:21:06 by pjedrycz          #+#    #+#             */
/*   Updated: 2024/12/23 21:29:25 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Some basic shell feature - print working directory.
// This function will show in the terminal, your current
// working directory.
// 0 for success and 1 for failure.
int	pwd_builtin(t_data *data, char **args)
{
	char	buff[PATH_MAX];
	char	*cwd;

	(void)args;
	if (data->working_dir)
	{
		ft_putendl_fd(data->working_dir, STDOUT_FILENO);
		return (EXIT_SUCCESS);
	}
	cwd = getcwd(buff, PATH_MAX);
	if (cwd)
	{
		ft_putendl_fd(cwd, STDOUT_FILENO);
		return (EXIT_SUCCESS);
	}
	errmsg_cmd("pwd", NULL, strerror(errno), errno);
	return (EXIT_FAILURE);
}
