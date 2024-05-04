/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:36:06 by yliu              #+#    #+#             */
/*   Updated: 2024/05/04 00:13:17 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_H
# define PROCESS_H

# include "libft.h"
# include "parse_string.h"
# include "pipex.h"
# include "xwrapper.h"
# include <fcntl.h>
# include <string.h>

# define PATH "PATH="

typedef enum e_errno
{
	PERMISSION_DENIED = 13
}						t_errno;

typedef struct s_command
{
	const char			*entire_path;
	const char			**sep_by_space;
}						t_command;

typedef struct s_fd		t_fd;
typedef struct s_arg	t_arg;

int						return_infile_fd(const char *filename);
int						return_outfile_fd(const char *outfile);
void					overtake_io(int new_in, int new_out);
const char				*return_entire_path(const char *basename,
							const char *envp[]);
void					exec_process(const char *arg_str, const char *envp[]);
pid_t					fork_exec(int cmd_num, int input_fd, int output_fd,
							t_arg *arg_info);
#endif
