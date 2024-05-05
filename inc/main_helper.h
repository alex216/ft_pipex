/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helper.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 14:19:15 by yliu              #+#    #+#             */
/*   Updated: 2024/05/05 10:16:46 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HELPER_H
# define MAIN_HELPER_H

# include "here_doc.h"
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
}				t_arg;

void			mk_xpipe(int *pip_arr, int i);
int				pipe_read_fd(int *pipefd, int i);
int				pipe_write_fd(int *pipefd, int i);
void			init_arg_info(int argc, const char **argv, const char **envp,
					t_arg *arg_info);
void			init_fd_info(t_arg *arg_cve_info, t_fd *fd_info);
#endif