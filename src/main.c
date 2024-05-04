/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:57:53 by yliu              #+#    #+#             */
/*   Updated: 2024/05/04 09:48:05 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "pipex.h"
#include "process.h"

// __attribute__((destructor)) void destructor(void)
// {
// 	system("leaks --atExit -- ./pipex");
// }

int	main(int argc, const char **argv, const char **envp)
{
	int		pfd_pp[argc - 4][2];
	t_arg	arg_cve_info;
	t_fd	fd_info;
	int		i;

	init_arg_info(argc, argv, envp, &arg_cve_info);
	init_fd_info(argc, argv, &fd_info);
	i = 0;
	while (is_first(i) || is_middle(i, argc) || is_last(i, argc))
	{
		if (is_first(i) || is_middle(i, argc))
			xpipe(pfd_pp[i]);
		if (is_middle(i, argc) || is_last(i, argc))
			fd_info.import_fd = pfd_pp[i - 1][0];
		if (is_first(i) || is_middle(i, argc))
			fd_info.export_fd = pfd_pp[i][1];
		if (is_first(i))
			fork_exec(i, fd_info.infile_fd, fd_info.export_fd, &arg_cve_info);
		else if (is_last(i, argc))
			fork_exec(i, fd_info.import_fd, fd_info.outfile_fd, &arg_cve_info);
		else
			fork_exec(i, fd_info.import_fd, fd_info.export_fd, &arg_cve_info);
		if (is_first(i) || is_middle(i, argc))
			close(pfd_pp[i][1]);
		i++;
	}
	return (0);
}
