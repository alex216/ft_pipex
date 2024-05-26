/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_pipe_fds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:48:50 by yliu              #+#    #+#             */
/*   Updated: 2024/05/26 12:53:17 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_helper.h"

void	open_pipe_fds(int cmd_i, int **pipefd, int cmd_num)
{
	if (is_first(cmd_i) || is_middle(cmd_i, cmd_num))
		xpipe(pipefd[cmd_i]);
}
