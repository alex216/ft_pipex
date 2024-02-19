/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:05:26 by yliu              #+#    #+#             */
/*   Updated: 2024/02/19 18:05:34 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	replace_fd(int dst, int src)
{
	if (dup2(src, dst) == FAIL)
		exit_errno_msg(strerror(errno));
	if (close(src) == FAIL)
		exit_errno_msg(strerror(errno));
}
