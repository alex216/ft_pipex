/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:16:51 by yliu              #+#    #+#             */
/*   Updated: 2024/02/20 15:38:55 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define CHILD 0
# define SUCCESS 0
# define PARENT 1
# ifndef FAIL
#  define FAIL -1
# endif

# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"
# include "process.h"
# include "utils.h"
# include <fcntl.h>

extern char		**environ;

# define STATIC
// # ifdef GOOGLE_TEST
// #  define STATIC
// # else
// #  define STATIC static
// # endif

typedef struct s_command
{
	const char	*full_path;
	char		**all_string;
}				t_command;

int				main(int argc, char **argv);

// # ifdef GOOGLE_TEST
const char		*_create_cmd_full_path(const char *cmd_first_string);
// # endif

#endif
