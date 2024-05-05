/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_xfork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 14:47:03 by yliu              #+#    #+#             */
/*   Updated: 2024/05/05 13:16:29 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_helper.h"
#include "pipex.h"
#include "utils.h"

static int	open_infile_fd(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == FAIL)
		exit(print_error(filename, strerror(PERMISSION_DENIED), 1));
	return (fd);
}

static int	open_created_outfile_fd(const char *filename)
{
	int	fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == FAIL)
		exit(print_error(filename, strerror(errno), 1));
	return (fd);
}

static int	open_appended_outfile_fd(const char *filename)
{
	int	fd;

	fd = open(filename, O_WRONLY | O_APPEND | O_TRUNC, 0644);
	if (fd == FAIL)
		exit(print_error(filename, strerror(errno), 1));
	return (fd);
}

static void	_open_pipe(int cmd_i, int *pipefd, t_arg *arg_info, t_fd *fd_info)
{
	const char	**argv;
	int			cmd_num;
	int			argc;

	argv = arg_info->argv;
	argc = arg_info->argc;
	cmd_num = arg_info->cmd_num;
	if (is_first(cmd_i) || is_middle(cmd_i, cmd_num))
		mk_xpipe(pipefd, cmd_i);
	if (is_first(cmd_i))
	{
		if (arg_info->is_heredoc)
			; // fd_info->infile_fd = return_heredoc_fd(argv[2]);
		else
			fd_info->infile_fd = open_infile_fd(argv[1]);
	}
	if (is_last(cmd_i, cmd_num))
	{
		if (arg_info->is_heredoc)
			fd_info->outfile_fd = open_appended_outfile_fd(argv[argc - 1]);
		else
			fd_info->outfile_fd = open_created_outfile_fd(argv[argc - 1]);
	}
}

static void	_close_pipe(int cmd_i, int *pipefd, t_arg *arg_info, t_fd *fd_info)
{
	if (is_first(cmd_i) || is_middle(cmd_i, arg_info->cmd_num))
		close(pipe_write_fd(pipefd, cmd_i));
	if (is_middle(cmd_i, arg_info->cmd_num) || is_last(cmd_i,
			arg_info->cmd_num))
		close(pipe_read_fd(pipefd, cmd_i - 1));
	if (is_first(cmd_i))
		close(fd_info->infile_fd);
	if (is_last(cmd_i, arg_info->argc))
		close(fd_info->outfile_fd);
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

	cmd_num = arg_cve_info->cmd_num;
	cmd_i = 0;
	while (is_first(cmd_i) || is_middle(cmd_i, cmd_num) || is_last(cmd_i,
			cmd_num))
	{
		_open_pipe(cmd_i, pipefd, arg_cve_info, fd_info);
		_refresh_fd_info(cmd_num, fd_info, cmd_i, pipefd);
		xfork_exec(cmd_i, fd_info, arg_cve_info);
		_close_pipe(cmd_i, pipefd, arg_cve_info, fd_info);
		cmd_i++;
	}
}
