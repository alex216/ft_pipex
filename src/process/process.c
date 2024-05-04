/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:34:24 by yliu              #+#    #+#             */
/*   Updated: 2024/05/04 00:24:40 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "pipex.h"
#include "process.h"
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

pid_t	fork_exec(int cmd_num, int input_fd, int output_fd, t_arg *arg_info)
{
	pid_t	pid;

	pid = xfork();
	if (pid == CHILD)
	{
		overtake_io(input_fd, output_fd);
		exec_process(return_cmd(arg_info->argv, cmd_num), arg_info->envp);
	}
	return (pid);
}
