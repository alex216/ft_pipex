/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:34:24 by yliu              #+#    #+#             */
/*   Updated: 2024/05/02 18:52:02 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "pipex.h"
#include "process.h"
#include "utils.h"
#include "xwrapper.h"

/*
 pipe():	 ------ <-[0]<- ---
			| main |       | p |
			 ------ ->[1]-> ---

 fork():	 ------ <-[0]<- --- ->[0]-> ------
			| main |       | p |       | cmd1 |
			 ------ ->[1]-> --- <-[1]<- ------

 first pipe: ------ <-[0]<- ---         ------  STDIN :infile
			| main |       | p |       | cmd1 |
			 ------ ->[1]-> --- <-[1]<- ------  STDOUT:curr_pft[1]

 middle pipe:------ <-[0]<- ---         ------  STDIN :prev_pfd[0]
			| main |       | p |       | cmd1 |
			 ------ ->[1]-> --- <-[1]<- ------  STDOUT:curr_pfd[1]

 last pipe:	 ------ <-[0]<- --- ->[0]-> ------  STDIN :curr_pfd[0]
			| main |       | p |       | cmdX |
			 ------ ->[1]-> ---         ------  STDOUT:outfile
*/

void	exec_first(const char **argv,int cmd_num, const char *infile, int pipefd[],
		const char *envp[])
{
	xdup2(return_infile_fd(argv, infile), STDIN_FILENO);
	xdup2(pipefd[1], STDOUT_FILENO);
	xclose(pipefd[0]);
	xclose(pipefd[1]);
	exec_process(argv[cmd_num + 1], envp);
}

void	exec_middle(const char **argv, int cmd_num,int prev_pfd[], int curr_pfd[], const char *envp[])
{
	xdup2(prev_pfd[0], STDIN_FILENO);
	xclose(prev_pfd[0]);
	xclose(prev_pfd[1]);

	xdup2(curr_pfd[1], STDOUT_FILENO);
	xclose(curr_pfd[0]);
	xclose(curr_pfd[1]);

	exec_process(argv[cmd_num + 1], envp);
}

void	exec_last(const char **argv,int cmd_num, const char *outfile, int pipefd[], const char *envp[])
{
	xdup2(pipefd[0], STDIN_FILENO);
	xdup2(return_outfile_fd(outfile), STDOUT_FILENO);
	xclose(pipefd[1]);
	exec_process(argv[cmd_num + 1], envp);
}
