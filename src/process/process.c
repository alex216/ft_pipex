/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:34:24 by yliu              #+#    #+#             */
/*   Updated: 2024/05/03 18:01:00 by yliu             ###   ########.fr       */
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

//////////////////////////////////////////

pid_t	fork_exec(const char **argv, int cmd_num, int total, int file_fd,
		int prev_fd[], int curr_fd[], const char *envp[])
{
	pid_t	pid;

	pid = xfork();
	if (pid == CHILD)
	{
		if (cmd_num == 0)
			overtake_io(file_fd, curr_fd[1]);
		else if (cmd_num == total - 1)
			overtake_io(prev_fd[0], file_fd);
		else
			overtake_io(prev_fd[0], curr_fd[1]);
		exec_process(return_cmd(argv, cmd_num), envp);
	}
	return (pid);
}
