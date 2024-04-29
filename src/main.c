/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:57:53 by yliu              #+#    #+#             */
/*   Updated: 2024/04/24 15:21:56 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// __attribute__((destructor)) void destructor(void)
// {
// 	system("leaks --atExit -- ./pipex");
// }

int	main(int argc, const char **argv, const char *envp[])
{
	pid_t	pid;
	int		pipefd[2];

	if (argc != 5)
		exit(42);
	if (pipe(pipefd) == FAIL)
		exit(print_errno(strerror(errno)));
	pid = fork();
	if (pid == FAIL)
		exit(print_errno(strerror(errno)));
	if (pid == 0)
		exec_child(argv, argv[1], pipefd, envp);
	else
		exec_parent(argv, argv[4], pipefd, envp);
	return (0);
}
