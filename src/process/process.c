/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:34:24 by yliu              #+#    #+#             */
/*   Updated: 2024/04/03 16:03:41 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "process.h"
#include "utils.h"

void	exec_child(const char **argv, const char *infile, int pipefd[],
		const char *envp[])
{
	xdup2(return_infile_fd(argv, infile), STDIN_FILENO);
	xdup2(pipefd[1], STDOUT_FILENO);
	xclose(pipefd[0]);
	exec_process(argv[2], envp);
}

void	exec_parent(const char **argv, const char *outfile, int pipefd[],
		const char *envp[])
{
	xdup2(pipefd[0], STDIN_FILENO);
	xdup2(return_outfile_fd(outfile), STDOUT_FILENO);
	xclose(pipefd[1]);
	exec_process(argv[3], envp);
}
