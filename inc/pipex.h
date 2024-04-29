/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:16:51 by yliu              #+#    #+#             */
/*   Updated: 2024/04/25 11:34:49 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "dlist.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"
# include "parse_string.h"
# include "process.h"
# include "utils.h"
# include "xwrapper.h"
# include <fcntl.h>

# define PARENT 1
# ifndef FAIL
#  define FAIL -1
# endif

int	main(int argc, const char **argv, const char *envp[]);

#endif
