/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_pipe_fds.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:41:04 by yliu              #+#    #+#             */
/*   Updated: 2024/05/26 12:53:01 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_helper.h"

void	close_pipe_fds(int cmd_i, int **pipefd, int cmd_num)
{
	if (is_first(cmd_i) || is_middle(cmd_i, cmd_num))
		close(pipe_write_fd(pipefd, cmd_i));
	if (is_middle(cmd_i, cmd_num) || is_last(cmd_i, cmd_num))
		close(pipe_read_fd(pipefd, cmd_i - 1));
}
