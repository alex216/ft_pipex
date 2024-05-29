/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_xfork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 14:47:03 by yliu              #+#    #+#             */
/*   Updated: 2024/05/29 21:26:45 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "main_helper.h"
#include "utils.h"

static void	_del_heredoc(int heredoc_fd, char *filename)
{
	close(heredoc_fd);
	unlink(filename);
	free(filename);
}

static void	_refresh_fd_info(int cmd_num, t_fd *fd_info, int cmd_i,
		int **pipefd)
{
	if (is_middle(cmd_i, cmd_num) || is_last(cmd_i, cmd_num))
		fd_info->import_fd = pipe_read_fd(pipefd, cmd_i - 1);
	if (is_first(cmd_i) || is_middle(cmd_i, cmd_num))
		fd_info->export_fd = pipe_write_fd(pipefd, cmd_i);
}

static void	_open_pipe_exec_close_pipe(int cmd_i, int **pipefd, t_arg *arg_info,
		t_fd *fd_info)
{
	int	cmd_num;

	cmd_num = arg_info->cmd_num;
	open_pipe_fds(cmd_i, pipefd, cmd_num);
	_refresh_fd_info(cmd_num, fd_info, cmd_i, pipefd);
	xfork_exec(cmd_i, fd_info, arg_info);
	close_pipe_fds(cmd_i, pipefd, cmd_num);
}

static void	_exec_first_proc(t_arg *arg_info, t_fd *fd_info, int **pipefd)
{
	if (arg_info->is_heredoc)
		fd_info->infile_fd = _open_infile_fd(heredoc_file(arg_info->argv[2],
					arg_info));
	_open_pipe_exec_close_pipe(0, pipefd, arg_info, fd_info);
	if (arg_info->is_heredoc)
		_del_heredoc(fd_info->infile_fd, arg_info->heredoc_filename);
}

void	loop_xfork(t_arg *arg_info, t_fd *fd_info, int **pipefd)
{
	int	cmd_i;
	int	cmd_num;

	cmd_num = arg_info->cmd_num;
	_exec_first_proc(arg_info, fd_info, pipefd);
	cmd_i = 1;
	while (is_middle(cmd_i, cmd_num) || is_last(cmd_i, cmd_num))
	{
		_open_pipe_exec_close_pipe(cmd_i, pipefd, arg_info, fd_info);
		cmd_i++;
	}
	while (wait(NULL) != -1)
		continue ;
	if (errno != ECHILD)
		exit(1);
}
