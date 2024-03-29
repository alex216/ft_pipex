/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:38:42 by yliu              #+#    #+#             */
/*   Updated: 2024/02/19 18:40:02 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# ifndef FAIL
#  define FAIL -1
# endif
# include "ft_printf.h"
# include "libft.h"
# include <string.h>
# include <sys/errno.h>
# include <unistd.h>

void	exit_errno_msg(const char *errno_msg);
void	exit_with_perror(const char *errno_msg);

#endif
