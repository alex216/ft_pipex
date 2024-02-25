/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:34:24 by yliu              #+#    #+#             */
/*   Updated: 2024/02/24 03:19:08 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "process.h"
#include "utils.h"

void	exec_child(const char *arg_str, const char *infile, int pipefd[],
		const char *envp[])
{
	dup2_fd(return_infile_fd(infile), STDIN_FILENO);
	dup2_fd(pipefd[1], STDOUT_FILENO);
	close_fd(pipefd[0]);
	exec_process(arg_str, envp);
}

void	exec_parent(const char *arg_str, const char *outfile, int pipefd[],
		const char *envp[])
{
	dup2_fd(pipefd[0], STDIN_FILENO);
	dup2_fd(return_outfile_fd(outfile), STDOUT_FILENO);
	close_fd(pipefd[1]);
	exec_process(arg_str, envp);
}
