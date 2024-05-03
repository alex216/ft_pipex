/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:57:53 by yliu              #+#    #+#             */
/*   Updated: 2024/05/03 12:13:09 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "pipex.h"

// __attribute__((destructor)) void destructor(void)
// {
// 	system("leaks --atExit -- ./pipex");
// }
//

void	checker(int pipefd[])
{
	char *buf = calloc(1000, 1);
	read(pipefd[0] ,buf, 500);
	ft_dprintf(2, buf);
}

static pid_t fork_exec(const char **argv, int num, const char *file,
					  int prev_fd[], int curr_fd[], const char *envp[])
{
	pid_t pid = xfork();
	if (pid == CHILD)
	{
		if (num == 1)
			exec_first(argv, 1, file, curr_fd, envp);
		else if(num == 3)
			exec_last(argv, 3, file, prev_fd, envp);
		else
			exec_middle(argv, 2, prev_fd, curr_fd, envp);
	}
	return (pid);
}

int	main(int argc, const char **argv, const char *envp[])
{
	int	pfd_pp[2][2];
	const char *infile; const char *outfile;
	pid_t pid0,pid1; (void)pid0;(void)pid1;
	infile = argv[1]; outfile = argv[argc - 1];

	///////////// 1
	xpipe(pfd_pp[0]);
	pid0 = fork_exec(argv, 1, infile, NULL, pfd_pp[0], envp);
	close(pfd_pp[0][1]);
	// checker(pfd_pp[0]);

	///////////// 2
	xpipe(pfd_pp[1]);
	pid1 = fork_exec(argv, 2, NULL, pfd_pp[0], pfd_pp[1], envp);
	// checker(pfd_pp[1]);

	///////////// 3
	fork_exec(argv, 3, outfile, pfd_pp[1], NULL, envp);

	return (0);
}
