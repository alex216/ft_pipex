/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xclose.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:05:45 by yliu              #+#    #+#             */
/*   Updated: 2024/04/04 18:07:40 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	xclose(int fd)
{
	if (close(fd) == FAIL)
		exit(print_errno(strerror(errno)));
}
