/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:38:42 by yliu              #+#    #+#             */
/*   Updated: 2024/04/04 18:18:56 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# ifndef FAIL
#  define FAIL -1
# endif
# define CMD_NOT_FOUND "command not found"
# include "ft_printf.h"
# include "libft.h"
# include <string.h>
# include <sys/errno.h>
# include <unistd.h>

int			print_error(const char *basename, char *str, int exit_status);
int			print_errno(const char *errno_msg);
void		free_list(void **list);
char		*strjooin(int argc, const char *a, const char *b, ...);
const char	*search_path_list(const char *envp[]);
bool		xaccess_is_f_ok(const char *name);
bool		xaccess_is_f_ok_alt(const char *name);
bool		xaccess_is_x_ok(const char *name);

#endif
