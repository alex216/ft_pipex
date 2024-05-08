/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_xfork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 14:47:03 by yliu              #+#    #+#             */
/*   Updated: 2024/05/08 11:50:41 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "main_helper.h"
#include "utils.h"

static void	_del_heredoc(char *filename)
{
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

void	loop_xfork(t_arg *arg_cve_info, t_fd *fd_info, int **pipefd)
{
	int	cmd_i;
	int	cmd_num;

	cmd_num = arg_cve_info->cmd_num;
	cmd_i = 0;
	while (is_first(cmd_i) || is_middle(cmd_i, cmd_num) || is_last(cmd_i,
			cmd_num))
	{
		open_fds(cmd_i, pipefd, arg_cve_info, fd_info);
		_refresh_fd_info(cmd_num, fd_info, cmd_i, pipefd);
		xfork_exec(cmd_i, fd_info, arg_cve_info);
		close_fds(cmd_i, pipefd, arg_cve_info, fd_info);
		cmd_i++;
	}
	if (arg_cve_info->is_heredoc)
		_del_heredoc(arg_cve_info->heredoc_filename);
	while (wait(NULL) != -1)
		continue ;
	if (errno != ECHILD)
		exit(1);
}
