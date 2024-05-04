/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helper.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 14:19:15 by yliu              #+#    #+#             */
/*   Updated: 2024/05/04 16:30:01 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HELPER_H
# define MAIN_HELPER_H

# include "xwrapper.h"
# include <fcntl.h>

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
}				t_arg;

void			_mk_xpipe(int *pip_arr, int i);
int				_pipe_read_fd(int *pipefd, int i);
int				_pipe_write_fd(int *pipefd, int i);
void			init_arg_info(int argc, const char **argv, const char **envp,
					t_arg *arg_info);
void			init_fd_info(int argc, const char **argv, t_fd *fd_info);
#endif
