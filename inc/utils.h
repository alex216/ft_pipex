/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:38:42 by yliu              #+#    #+#             */
/*   Updated: 2024/04/23 19:29:06 by yliu             ###   ########.fr       */
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
const char	*search_path_list(const char *envp[]);
bool		is_basename_has_slash(const char *basename);

bool		xaccess_is_f_ok(const char *name);
bool		xaccess_is_f_ok_alt(const char *name);
bool		xaccess_is_x_ok(const char *name);

char		*return_printable(const t_lst *lst_p);

t_lst		*create_lst_node(const char *str);
void		free_record(t_record *token_p);

#endif
