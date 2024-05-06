/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overtake_io_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:56:57 by yliu              #+#    #+#             */
/*   Updated: 2024/05/06 09:05:16 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xfork_exec.h"

static void	_overtake_stdin_fd(int pfd)
{
	xdup2(pfd, STDIN_FILENO);
	xclose(pfd);
}

static void	_overtake_stdout_fd(int pfd)
{
	xdup2(pfd, STDOUT_FILENO);
	xclose(pfd);
}

void	overtake_io_fd(int new_in, int new_out)
{
	_overtake_stdin_fd(new_in);
	_overtake_stdout_fd(new_out);
}
