/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 14:47:03 by yliu              #+#    #+#             */
/*   Updated: 2024/05/05 11:12:42 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_helper.h"
#include "pipex.h"

static void	_open_pipe(int cmd_num, int cmd_i, int *pipefd)
{
	if (is_first(cmd_i) || is_middle(cmd_i, cmd_num))
		mk_xpipe(pipefd, cmd_i);
}

static void	_close_pipe(int cmd_num, int cmd_i, int *pipefd)
{
	if (is_first(cmd_i) || is_middle(cmd_i, cmd_num))
		close(pipe_write_fd(pipefd, cmd_i));
	if (is_middle(cmd_i, cmd_num) || is_last(cmd_i, cmd_num))
		close(pipe_read_fd(pipefd, cmd_i - 1));
	// if (
}

static void	_refresh_fd_info(int cmd_num, t_fd *fd_info, int cmd_i, int *pipefd)
{
	if (is_middle(cmd_i, cmd_num) || is_last(cmd_i, cmd_num))
		fd_info->import_fd = pipe_read_fd(pipefd, cmd_i - 1);
	if (is_first(cmd_i) || is_middle(cmd_i, cmd_num))
		fd_info->export_fd = pipe_write_fd(pipefd, cmd_i);
}

void	loop_xfork(t_arg *arg_cve_info, t_fd *fd_info, int *pipefd)
{
	int	cmd_i;
	int	cmd_num;

	cmd_i = 0;
	cmd_num = arg_cve_info->cmd_num;
	while (is_first(cmd_i)
		|| is_middle(cmd_i, cmd_num)
		|| is_last(cmd_i, cmd_num))
	{
		_open_pipe(cmd_num, cmd_i, pipefd);
		_refresh_fd_info(cmd_num, fd_info, cmd_i, pipefd);
		xfork_exec(cmd_i, fd_info, arg_cve_info);
		_close_pipe(cmd_num, cmd_i, pipefd);
		cmd_i++;
	}
}
