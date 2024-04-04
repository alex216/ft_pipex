/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:38:42 by yliu              #+#    #+#             */
/*   Updated: 2024/04/04 12:24:24 by yliu             ###   ########.fr       */
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

int		dprint_with_bash_colon(const char *basename, char *str,
			int exit_status);
void	exit_errno_msg(const char *errno_msg);
void	free_list(void **list);

#endif
