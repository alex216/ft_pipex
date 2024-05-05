/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xfork_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:34:24 by yliu              #+#    #+#             */
/*   Updated: 2024/05/05 14:33:21 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "pipex.h"
#include "utils.h"
#include "xfork_exec.h"
#include "xwrapper.h"

/*
 pipe():
 ------ <-[0]<- ---
| main |       | p |
 ------ ->[1]-> ---

 fork():
 ------ <-[0]<- --- ->[0]-> ------
| main |       | p |       | cmd1 |
 ------ ->[1]-> --- <-[1]<- ------

 first pipe:
 ------ <-[0]<- --- -       ------  STDIN :infile or here_doc
| main |       | p | \     | cmd1 |
 ------ ->[1]-> --- <-[1]<- ------  STDOUT:curr_pft[1]
						\
 middle pipe:           \
 ------ <-[0]<- --- -    -> ------  STDIN :prev_pfd[0]
| main |       | p | \     | cmd1 |
 ------ ->[1]-> --- <-[1]<- ------  STDOUT:curr_pfd[1]
						\
 last pipe:             \
 ------                  -> ------  STDIN :prev_pfd[0]
| main |                   | cmdX |
 ------                     ------  STDOUT:outfile
*/

static void	_overtake_io(int cmd_i, t_fd *fd_info, int cmd_num)
{
	if (is_first(cmd_i))
		overtake_io_fd(fd_info->infile_fd, fd_info->export_fd);
	else if (is_middle(cmd_i, cmd_num))
		overtake_io_fd(fd_info->import_fd, fd_info->export_fd);
	else if (is_last(cmd_i, cmd_num))
		overtake_io_fd(fd_info->import_fd, fd_info->outfile_fd);
}

pid_t	xfork_exec(int cmd_i, t_fd *fd_info, t_arg *arg_info)
{
	pid_t		pid;
	const char	*cmd;

	pid = xfork();
	if (pid == CHILD)
	{
		_overtake_io(cmd_i, fd_info, arg_info->cmd_num);
		cmd = return_cmd(arg_info->argv, cmd_i, arg_info->is_heredoc);
		exec_process(cmd, arg_info->envp);
	}
	return (pid);
}
