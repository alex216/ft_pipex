/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:36:06 by yliu              #+#    #+#             */
/*   Updated: 2024/04/25 10:14:28 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_H
# define PROCESS_H

# include "libft.h"
# include "parse_string.h"
# include "xwrapper.h"
# include <fcntl.h>
# include <string.h>

# define PATH "PATH="

typedef enum e_errno
{
	PERMISSION_DENIED = 13
}				t_errno;

typedef struct s_command
{
	const char	*entire_path;
	const char	**sep_by_space;
}				t_command;

int				return_infile_fd(const char **argv, const char *filename);
int				return_outfile_fd(const char *outfile);
const char		*return_entire_path(const char *basename, const char *envp[]);
void			exec_process(const char *arg_str, const char *envp[]);
void			exec_child(const char **argv, const char *inflie, int pipefd[],
					const char *envp[]);
void			exec_parent(const char **argv, const char *outfile,
					int pipefd[], const char *envp[]);
#endif
