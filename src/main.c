/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:57:53 by yliu              #+#    #+#             */
/*   Updated: 2024/05/03 12:49:08 by yliu             ###   ########.fr       */
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
	char *buf = calloc(10, 1);
	read(pipefd[0] ,buf, 10);
	ft_dprintf(2, buf);
}

static pid_t fork_exec(const char **argv, int cmd_num, int total, const char *file,
					  int prev_fd[], int curr_fd[], const char *envp[])
{
	pid_t pid = xfork();
	if (pid == CHILD)
	{
		if (cmd_num == 0)
			exec_first(argv, 0, file, curr_fd, envp);
		else if(cmd_num == total - 1)
			exec_last(argv, cmd_num, file, prev_fd, envp);
		else
			exec_middle(argv, cmd_num, prev_fd, curr_fd, envp);
	}
	return (pid);
}

int	main(int argc, const char **argv, const char *envp[])
{
	const char *infile; const char *outfile;
	infile = argv[1]; outfile = argv[argc - 1];
	pid_t pid0,pid1; (void)pid0;(void)pid1;

	int total_cmd;
	total_cmd = argc - 3;
	int cmd_num;
	int	pfd_pp[total_cmd - 1][2];

	///////////// 0
	cmd_num = 0;
	xpipe(pfd_pp[0]);
	pid0 = fork_exec(argv, cmd_num, total_cmd, infile, NULL, pfd_pp[0], envp);
	close(pfd_pp[cmd_num][1]);
	cmd_num++;

	///////////// 1, 2
	while (cmd_num <= total_cmd - 2)
	{
		xpipe(pfd_pp[cmd_num]);
		pid1 = fork_exec(argv, cmd_num, total_cmd, NULL, pfd_pp[cmd_num - 1], pfd_pp[cmd_num], envp);
		close(pfd_pp[cmd_num][1]);
		// checker(pfd_pp[1]);
		cmd_num++;
	}

	///////////// 3
	fork_exec(argv, cmd_num, total_cmd, outfile, pfd_pp[cmd_num - 1], NULL, envp);

	return (0);
}
