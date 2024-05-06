/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 13:21:45 by yliu              #+#    #+#             */
/*   Updated: 2024/05/06 11:28:04 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_helper.h"

void	close_pipes(int cmd_i, int **pipefd, t_arg *arg_info, t_fd *fd_info)
{
	int	cmd_num;

	cmd_num = arg_info->cmd_num;
	if (is_first(cmd_i) || is_middle(cmd_i, cmd_num))
		close(pipe_write_fd(pipefd, cmd_i));
	if (is_middle(cmd_i, cmd_num) || is_last(cmd_i, cmd_num))
		close(pipe_read_fd(pipefd, cmd_i - 1));
	if (is_first(cmd_i))
		close(fd_info->infile_fd);
	if (is_last(cmd_i, cmd_num))
		close(fd_info->outfile_fd);
}
