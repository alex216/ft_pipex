/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:57:53 by yliu              #+#    #+#             */
/*   Updated: 2024/05/03 18:04:54 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "pipex.h"
#include "process.h"

// __attribute__((destructor)) void destructor(void)
// {
// 	system("leaks --atExit -- ./pipex");
// }
//

void	checker(int pipefd[])
{
	char	*buf;

	buf = calloc(10, 1);
	read(pipefd[0], buf, 10);
	ft_dprintf(2, buf);
}

int	main(int argc, const char **argv, const char *envp[])
{
	int	infile_fd;
	int	outfile_fd;
	int	total_cmd;
	total_cmd = argc - 3;
	int	cmd_num;
	int	pfd_pp[total_cmd - 1][2];

	infile_fd = return_infile_fd(argv[1]);
	outfile_fd = return_outfile_fd(argv[argc - 1]);
	pid_t pid0, pid1;
	(void)pid0;
	(void)pid1;
	///////////// 0
	cmd_num = 0;
	xpipe(pfd_pp[0]);
	pid0 = fork_exec(argv, cmd_num, total_cmd, infile_fd, NULL, pfd_pp[0],
			envp);
	close(pfd_pp[cmd_num][1]);
	cmd_num++;
	///////////// 1, 2
	while (cmd_num <= total_cmd - 2)
	{
		xpipe(pfd_pp[cmd_num]);
		pid1 = fork_exec(argv, cmd_num, total_cmd, 0, pfd_pp[cmd_num - 1],
				pfd_pp[cmd_num], envp);
		close(pfd_pp[cmd_num][1]);
		cmd_num++;
	}
	///////////// 3
	fork_exec(argv, cmd_num, total_cmd, outfile_fd, pfd_pp[cmd_num - 1], NULL,
		envp);
	return (0);
}
