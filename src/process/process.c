/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:34:24 by yliu              #+#    #+#             */
/*   Updated: 2024/02/19 18:10:42 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "process.h"
#include "utils.h"

void	exec_child(const char *arg_str, const char *infile, int pipefd[],
		const char *envp[])
{
	replace_fd(STDIN_FILENO, return_infile_fd(infile));
	replace_fd(STDOUT_FILENO, pipefd[1]);
	close_fd(pipefd[0]);
	exec_process(arg_str, envp);
}

void	exec_parent(const char *arg_str, const char *outfile, int pipefd[],
		const char *envp[])
{
	replace_fd(STDIN_FILENO, pipefd[0]);
	replace_fd(STDOUT_FILENO, return_outfile_fd(outfile));
	close_fd(pipefd[1]);
	exec_process(arg_str, envp);
}
