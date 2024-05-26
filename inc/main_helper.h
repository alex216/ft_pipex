/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helper.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 14:19:15 by yliu              #+#    #+#             */
/*   Updated: 2024/05/26 16:20:43 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HELPER_H
# define MAIN_HELPER_H

# include "here_doc.h"
# include "sys/wait.h"
# include "xfork_exec.h"
# include "xwrapper.h"
# include <fcntl.h>

# ifndef FAIL
#  define FAIL -1
# endif

typedef enum e_errno
{
	PERMISSION_DENIED = 13
}				t_errno;

typedef struct s_fd
{
	int			infile_fd;
	int			outfile_fd;
	int			import_fd;
	int			export_fd;
}				t_fd;

typedef struct s_arg
{
	const char	**argv;
	int			argc;
	const char	**envp;
	int			cmd_num;
	bool		is_heredoc;
	char		*heredoc_filename;
}				t_arg;

void			init_arg_info(int argc, const char **argv, const char **envp,
					t_arg *arg_info);
void			open_pipe_fds(int cmd_i, int **pipefd, int cmd_num);
void			close_pipe_fds(int cmd_i, int **pipefd, int cmd_num);
void			mock_redirect_ope(int cmd_i, int cmd_num, t_arg *arg_info,
					t_fd *fd_info);
void			loop_xfork(t_arg *arg_cve_info, t_fd *fd_info, int **pipefd);
int				_open_infile_fd(const char *filename);
#endif
