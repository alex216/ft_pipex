/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 14:18:47 by yliu              #+#    #+#             */
/*   Updated: 2024/05/05 13:35:05 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	mk_xpipe(int *pip_arr, int i)
{
	int	tmp_fd[2];

	xpipe(tmp_fd);
	pip_arr[2 * i] = tmp_fd[0];
	pip_arr[2 * i + 1] = tmp_fd[1];
}

int	pipe_read_fd(int *pipefd, int i)
{
	return (pipefd[2 * i + 0]);
}

int	pipe_write_fd(int *pipefd, int i)
{
	return (pipefd[2 * i + 1]);
}
