/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpipe.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:01:53 by yliu              #+#    #+#             */
/*   Updated: 2024/05/01 10:44:05 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xwrapper.h"

void	xpipe(int *pipefd)
{
	if (pipe(pipefd) == FAIL)
		exit(print_errno(strerror(errno)));
}