/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:57:53 by yliu              #+#    #+#             */
/*   Updated: 2024/05/04 13:13:06 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// __attribute__((destructor)) void destructor(void)
// {
// 	system("leaks --atExit -- ./pipex");
// }
//
static void	mk_xpipe(int *pip_arr, int i)
{
	int	tmp_fd[2];

	xpipe(tmp_fd);
	pip_arr[2 * i] = tmp_fd[0];
	pip_arr[2 * i + 1] = tmp_fd[1];
}

int	main(int argc, const char **argv, const char **envp)
{
	t_arg	arg_cve_info;
	t_fd	fd_info;
	int		i;
	int		*pfd_malloc;

	pfd_malloc = malloc(2 * (argc - 4));
	init_arg_info(argc, argv, envp, &arg_cve_info);
	init_fd_info(argc, argv, &fd_info);
	i = 0;
	while (is_first(i) || is_middle(i, argc) || is_last(i, argc))
	{
		if (is_first(i) || is_middle(i, argc))
			mk_xpipe(pfd_malloc, i);
		if (is_middle(i, argc) || is_last(i, argc))
			fd_info.import_fd = pfd_malloc[2 * (i - 1)];
		if (is_first(i) || is_middle(i, argc))
			fd_info.export_fd = pfd_malloc[2 * i + 1];
		xfork_exec(i, &fd_info, &arg_cve_info);
		if (is_first(i) || is_middle(i, argc))
			close(pfd_malloc[2 * i + 1]);
		i++;
	}
	return (0);
}
