/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_trunc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanski <dtanski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:18:54 by dtanski           #+#    #+#             */
/*   Updated: 2025/03/02 09:07:51 by dtanski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*get_relative_path(char *file_to_open)
{
	char	*path;
	char	*ret;

	if (file_to_open[0] == '/')
		return (ft_strdup(file_to_open));
	path = ft_strdup("./");
	ret = ft_strjoin(path, file_to_open);
	printf("PARSING - Get_rel_path function return : %s\n", ret);
	return (ret);
}

static void	open_outfile_trunc(t_io_fds *io, char *file, char *var_filename)
{
	if (!remove_old_file_ref(io, false))
		return ;
	io->outfile = ft_strdup(file);
	if (io->outfile && io->outfile[0] == '\0')
	{
		errmsg_cmd(var_filename, NULL, "ambiguous redirect", false);
		return ;
	}
	io->fd_out = open(io->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (io->fd_out == -1)
		errmsg_cmd(io->outfile, NULL, strerror(errno), false);
}

void	parse_trunc(t_command	**last_cmd, t_token **token_lst)
{
	t_token		*tmp;
	t_command	*cmd;

	tmp = *token_lst;
	cmd = lst_last_cmd(*last_cmd);
	init_io(cmd);
	open_outfile_trunc(cmd->io_fds, tmp->next->str, tmp->next->str_backup);
	if (tmp->next->next)
		tmp = tmp->next->next;
	else
		tmp = tmp->next;
	*token_lst = tmp;
}
