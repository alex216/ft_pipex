/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:29:58 by yliu              #+#    #+#             */
/*   Updated: 2024/02/19 16:19:02 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	close_fd(int fd)
{
	if (close(fd) == FAIL)
		exit_errno_msg(strerror(errno));
}

void	replace_fd(int dst, int src)
{
	if (dup2(src, dst) == FAIL)
		exit_errno_msg(strerror(errno));
	if (close(src) == FAIL)
		exit_errno_msg(strerror(errno));
}

void	exit_errno_msg(char *errno_msg)
{
	ft_printf("%s\n", errno_msg);
	exit(42);
}
