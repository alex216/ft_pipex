/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:57:53 by yliu              #+#    #+#             */
/*   Updated: 2024/02/20 15:43:26 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// __attribute__((destructor)) void destructor(void)
// {
// 	system("leaks a.out");
// }

int	main(int argc, const char **argv, const char *envp[])
{
	pid_t	pid;
	int		pipefd[2];

	// TODO: create popen-like func
	if (argc != 5)
		exit(1);
	if (pipe(pipefd) == FAIL)
		exit_errno_msg(strerror(errno));
	pid = fork();
	if (pid == FAIL)
		exit_errno_msg(strerror(errno));
	if (pid == CHILD)
		exec_child(argv[2], argv[1], pipefd, envp);
	else
		exec_parent(argv[3], argv[4], pipefd, envp);
	return (0);
}
