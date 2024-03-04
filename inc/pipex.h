/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:16:51 by yliu              #+#    #+#             */
/*   Updated: 2024/03/04 19:42:03 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"
# include "process.h"
# include "utils.h"
# include <fcntl.h>

# ifdef GTEST
#  define STATIC extern
# else
#  define STATIC static
# endif

# define PATH "PATH="
# define SUCCESS 0
# define PARENT 1
# ifndef FAIL
#  define FAIL -1
# endif
# define NO_SUCH_FILE_OR_DIRECTORY 2
# define COMMAND_NOT_EXECUTABLE 126
# define NO_FILE_OR_CMD_ERR 127

# define SPACE 32
# define DOUBLE_QUOTE 34
# define SINGLE_QUOTE 39

typedef struct s_command
{
	const char	*entire_path;
	const char	**sep_by_space;
}				t_command;

int				main(int argc, const char **argv, const char *envp[]);

# ifdef GTEST
const char *_join_dir_base(const char **dirname_list,
	const char *basename);
const char *_search_path_list(const char *envp[]);
STATIC const char *_return_entire_path(const char *basename,
	const char *envp[]);
# endif

#endif
