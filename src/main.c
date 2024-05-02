/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:57:53 by yliu              #+#    #+#             */
/*   Updated: 2024/05/02 18:44:17 by yliu             ###   ########.fr       */
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

int	main(int argc, const char **argv, const char *envp[])
{
	int	cmd_num; int	pipefd[2][2]; pid_t	pid;
	const char *infile; const char *outfile;

	infile = argv[1]; outfile = argv[argc - 1];
	cmd_num = 1;

	xpipe(pipefd[0]);
	pid = xfork();
	if (pid == CHILD)
		exec_first(argv, cmd_num, infile, pipefd[0], envp);
	// close(pipefd[0][1]);
	// checker(pipefd[0]);

	// xpipe(pipefd[1]);
	// pid = xfork();
	// if (pid == CHILD)
	// 	exec_middle(argv, cmd_num, pipefd[0], pipefd[1], envp);
	cmd_num++;
	//
	// // }
	// waitpid(pid, NULL, 0);

	pid = xfork();
	if (pid == CHILD)
		exec_last(argv, cmd_num, outfile, pipefd[0], envp);

	return (0);
}
