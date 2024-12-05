/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 22:16:14 by pjedrycz          #+#    #+#             */
/*   Updated: 2024/12/05 21:57:51 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <errno.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <limits.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>

# include "libft.h"

// Macros //


// Global variable //
extern	int	g_last_exit_code;

// Structs //

typedef struct s_token
{
	char			*str;
	char			*str_backup;
	bool			var_exists;
	int				type;
	int				status;
	bool			join;
	struct s_token	*prev;
	struct s_token	*next;
}	t_token;

typedef	struct s_io_fds
{
	char	*infile;
	char	*outfile;
	char	*heredoc_delimiter;
	bool	heredoc_quotes;
	int		fd_in;
	int		fd_out;
	int		stdin_backup;
	int		stdout_backup;
}	t_io_fds;

typedef	struct s_command
{
	char				*cmd;
	char				*path;
	char				**args;
	bool				pipe_output;
	int					*pipe_fd;
	t_io_fds			*io_fds;
	struct s_command	*next;
	struct s_command	*prev;
}	t_command;

typedef struct s_data
{
	bool		interactive;
	t_token		*token;
	char		*usr_input;
	char		**env;
	char		*working_dir;
	char		*old_working_dir;
	t_command	*cmd;
	pid_t		pid;/////in execute.c
}	t_data;


// Enums //


// Functions //


// Error handling

//exit.c
void	exit_shell(t_data *data, int exno);

//error.c
int		errmsg_cmd(char	*comm, char *detail, char *err_msg, int err_nb);
void	errmsg(char *errmsg, char *detail, int quotes);
bool	usage_message(bool return_val);

//cleanup.c
void	free_ptr(void *ptr);
void	free_str_tab(char **tab);
void	free_data(t_data *data, bool clear_history);
void	close_fds(t_command *cmds, bool close_backups);
void	free_io(t_io_fds *io);

// Execution

//pipe.c
void	close_pipe_fds(t_command *cmds, t_command *skip_cmd);
bool	create_pipes(t_data *data);
bool	set_pipe_fds(t_command *cmds, t_command *c);

//file.io
bool	restore_io(t_io_fds *io);
bool	redirect_io(t_io_fds *io);
bool	check_infile_outfile(t_io_fds *io);

#endif