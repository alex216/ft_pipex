/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:34:24 by yliu              #+#    #+#             */
/*   Updated: 2024/03/03 19:16:24 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "process.h"
#include "utils.h"

void	exec_child(const char **argv, const char *infile, int pipefd[],
		const char *envp[])
{
	dup2_fd(return_infile_fd(argv, infile), STDIN_FILENO);
	dup2_fd(pipefd[1], STDOUT_FILENO);
	close_fd(pipefd[0]);
	exec_process(argv[2], envp);
}

void	exec_parent(const char **argv, const char *outfile, int pipefd[],
		const char *envp[])
{
	dup2_fd(pipefd[0], STDIN_FILENO);
	dup2_fd(return_outfile_fd(outfile), STDOUT_FILENO);
	close_fd(pipefd[1]);
	exec_process(argv[3], envp);
}
