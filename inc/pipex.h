/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:16:51 by yliu              #+#    #+#             */
/*   Updated: 2024/05/04 12:57:30 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "dlist.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"
# include "parse_string.h"
# include "utils.h"
# include "xfork_exec.h"
# include "xwrapper.h"
# include <fcntl.h>

# define CHILD 0
# define PARENT 1
# ifndef FAIL
#  define FAIL -1
# endif

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

// main_helper.c
void			init_arg_info(int argc, const char **argv, const char **envp,
					t_arg *arg_info);
void			init_fd_info(int argc, const char **argv, t_fd *fd_info);

// main.c
int				main(int argc, const char **argv, const char *envp[]);

#endif
