/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:16:51 by yliu              #+#    #+#             */
/*   Updated: 2024/04/04 12:13:31 by yliu             ###   ########.fr       */
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

typedef enum e_errno
{
	PERMISSION_DENIED = 13
}				t_errno;

typedef enum e_exit_status
{
	NOT_EXECUTABLE = 126,
	NO_FILE_OR_CMD_ERR = 127
}				t_exit_status;

typedef enum e_char
{
	SPACE = 32,
	DOUBLE_QUOTE = 34,
	SINGLE_QUOTE = 39
}				t_char;

typedef struct s_command
{
	const char	*entire_path;
	const char	**sep_by_space;
}				t_command;

int				main(int argc, const char **argv, const char *envp[]);

# ifdef GTEST
const char		*_join_dir_base(const char **dirname_list,
					const char *basename);
const char		*_search_path_list(const char *envp[]);
STATIC const char *_return_entire_path(const char *basename,
	const char *envp[]);
# endif

#endif
