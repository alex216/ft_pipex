/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:57:53 by yliu              #+#    #+#             */
/*   Updated: 2024/02/16 16:37:21 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "pipex.h"

// since this is not multi-thread process,
// malloc is safe to use.
void	_exec_child(char *cmd, int pipefd[])
{
	char	**cmdstr;

	cmdstr = xft_split(cmd);
	redirect_fd(pipefd[1], STDOUT_FILENO);
	close(pipefd[0]);
	execve(*cmdstr, cmdstr, environ);
	// exit_errno_msg(strerror(errno))
	// _exit(EXIT_FAILURE);
}

// since this is not multi-thread process,
// malloc is safe to use.
void	_exec_parent(char *cmd, int pipefd[])
{
	char	**cmdstr;

	cmdstr = xft_split(cmd);
	redirect_fd(pipefd[0], STDIN_FILENO);
	close(pipefd[1]);
	execve(*cmdstr, cmdstr, environ);
	// perror("execve");
	// exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		pipefd[2];
	char	*cmd;
	char	*cmd2;

	// TODO: should inpliment popen, pclose ?
	// TODO: whatif ls and wc is reversed in pid
	// TODO: wrapper func of dup, close, pipe, fork and etc
	// TODO: create popen-like func
	// 			int	mock-popen(const char *command, const char *mode);
	if (argc != 5)
		exit(42);
	cmd = argv[2];
	cmd2 = argv[3];
	if (pipe(pipefd) == FAIL)
		exit_errno_msg(strerror(errno));
	pid = fork();
	if (pid == FAIL)
		exit_errno_msg(strerror(errno));
	if (pid == CHILD)
		_exec_child(cmd, pipefd);
	else
		_exec_parent(cmd2, pipefd);
	return (0);
}
