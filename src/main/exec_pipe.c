/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 14:47:03 by yliu              #+#    #+#             */
/*   Updated: 2024/05/04 16:32:18 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	_refresh_fd_info(int argc, t_fd *fd_info, int cmd_i, int *pipefd)
{
	if (is_middle(cmd_i, argc) || is_last(cmd_i, argc))
		fd_info->import_fd = _pipe_read_fd(pipefd, cmd_i - 1);
	if (is_first(cmd_i) || is_middle(cmd_i, argc))
		fd_info->export_fd = _pipe_write_fd(pipefd, cmd_i);
}

static void	_alloc_pipe(int argc, int cmd_i, int *pipefd)
{
	if (is_first(cmd_i) || is_middle(cmd_i, argc))
		_mk_xpipe(pipefd, cmd_i);
}

static void	_free_pipe(int argc, int cmd_i, int *pipefd)
{
	if (is_first(cmd_i) || is_middle(cmd_i, argc))
		close(_pipe_write_fd(pipefd, cmd_i));
}

void	exec_pipe(t_arg *arg_cve_info, t_fd *fd_info, int *pipefd)
{
	int	cmd_i;
	int	argc;

	cmd_i = 0;
	argc = arg_cve_info->argc;
	while (is_first(cmd_i) || is_middle(cmd_i, argc) || is_last(cmd_i, argc))
	{
		_alloc_pipe(argc, cmd_i, pipefd);
		_refresh_fd_info(argc, fd_info, cmd_i, pipefd);
		xfork_exec(cmd_i, fd_info, arg_cve_info);
		_free_pipe(argc, cmd_i, pipefd);
		cmd_i++;
	}
	free(pipefd);
}
