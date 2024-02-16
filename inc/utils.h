/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:38:42 by yliu              #+#    #+#             */
/*   Updated: 2024/02/16 16:39:20 by yliu             ###   ########.fr       */
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

void	redirect_fd(int src, int dst);
void	exit_errno_msg(char *errno_msg);
char	**xft_split(char *string);

#endif
