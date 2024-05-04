/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:57:53 by yliu              #+#    #+#             */
/*   Updated: 2024/05/04 22:25:58 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// __attribute__((destructor)) void destructor(void)
// {
// 	system("leaks --atExit -- ./pipex");
// }
//

int	main(int argc, const char **argv, const char **envp)
{
	t_arg	arg_cve_info;
	t_fd	fd_info;
	int		*pipefd;

	if (argc < 5)
		exit(0);
	init_arg_info(argc, argv, envp, &arg_cve_info);
	pipefd = ft_xcalloc(2 * (argc - 4));
	init_fd_info(&arg_cve_info, &fd_info);
	exec_pipe(&arg_cve_info, &fd_info, pipefd);
	return (0);
}
