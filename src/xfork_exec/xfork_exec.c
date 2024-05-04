/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xfork_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:34:24 by yliu              #+#    #+#             */
/*   Updated: 2024/05/04 12:58:15 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "pipex.h"
#include "xfork_exec.h"
#include "utils.h"
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
 ------ <-[0]<- ---         ------  STDIN :infile
| main |       | p |       | cmd1 |
 ------ ->[1]-> --- <-[1]<- ------  STDOUT:curr_pft[1]

 middle pipe:
 ------ <-[0]<- ---         ------  STDIN :prev_pfd[0]
| main |       | p |       | cmd1 |
 ------ ->[1]-> --- <-[1]<- ------  STDOUT:curr_pfd[1]

 last pipe:
 ------ <-[0]<- --- ->[0]-> ------  STDIN :curr_pfd[0]
| main |       | p |       | cmdX |
 ------ ->[1]-> ---         ------  STDOUT:outfile
*/

static void	_overtake_io(int cmd_i, t_fd *fd_info, int argc)
{
		if (is_first(cmd_i))
			overtake_io_fd(fd_info->infile_fd, fd_info->export_fd);
		else if (is_middle(cmd_i, argc))
			overtake_io_fd(fd_info->import_fd, fd_info->export_fd);
		else
			overtake_io_fd(fd_info->import_fd, fd_info->outfile_fd);
}

pid_t	xfork_exec(int cmd_i, t_fd *fd_info, t_arg *arg_info)
{
	pid_t	pid;

	pid = xfork();
	if (pid == CHILD)
	{
		_overtake_io(cmd_i, fd_info, arg_info->argc);
		exec_process(return_cmd(arg_info->argv, cmd_i), arg_info->envp);
	}
	return (pid);
}
