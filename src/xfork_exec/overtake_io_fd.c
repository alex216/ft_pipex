/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overtake_io_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:56:57 by yliu              #+#    #+#             */
/*   Updated: 2024/05/04 13:00:03 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xfork_exec.h"

static void	_appoint_stdin_fd(int pfd)
{
	xdup2(pfd, STDIN_FILENO);
	xclose(pfd);
}

static void	_appoint_stdout_fd(int pfd)
{
	xdup2(pfd, STDOUT_FILENO);
	xclose(pfd);
}

void	overtake_io_fd(int new_in, int new_out)
{
	_appoint_stdin_fd(new_in);
	_appoint_stdout_fd(new_out);
}
