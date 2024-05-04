/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:57:53 by yliu              #+#    #+#             */
/*   Updated: 2024/05/04 09:21:27 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "pipex.h"
#include "process.h"

// __attribute__((destructor)) void destructor(void)
// {
// 	system("leaks --atExit -- ./pipex");
// }

static void	_init_arg_info(int argc, const char **argv, const char **envp,
		t_arg *arg_info)
{
	arg_info->argv = argv;
	arg_info->argc = argc;
	arg_info->envp = envp;
}

static void	_init_fd_info(int argc, const char **argv, t_fd *fd_info)
{
	fd_info->infile_fd = return_infile_fd(argv[1]);
	fd_info->outfile_fd = return_outfile_fd(argv[argc - 1]);
}

static bool _is_first(int cmd_num)
{
	return (cmd_num == 0);
}

static bool	_is_last(int cmd_num, int argc)
{
	return (cmd_num == argc - 4);
}

static bool	_is_middle(int cmd_num, int argc)
{
	return (cmd_num > 0 && cmd_num < argc - 4);
}

int	main(int argc, const char **argv, const char **envp)
{
	int		pfd_pp[argc - 4][2];
	t_arg	arg_info;
	t_fd	fd_info;
	int		i;

	_init_arg_info(argc, argv, envp, &arg_info);
	_init_fd_info(argc, argv, &fd_info);
	i = 0;
	// while (!_is_last(i, argc))
	while (_is_first(i) || _is_middle(i, argc) || _is_last(i, argc))
	{
		if (_is_first(i) || _is_middle(i, argc))
			xpipe(pfd_pp[i]);
	
		if (_is_middle(i, argc))
			fd_info.import_fd = pfd_pp[i - 1][0];
		if (_is_first(i) || _is_middle(i, argc))
			fd_info.export_fd = pfd_pp[i][1];
	
		if (_is_first(i))
			fork_exec(i, fd_info.infile_fd, fd_info.export_fd, &arg_info);
		else if (_is_last(i, argc))
			fork_exec(i, pfd_pp[i - 1][0], fd_info.outfile_fd, &arg_info);
		else
			fork_exec(i, fd_info.import_fd, fd_info.export_fd, &arg_info);

		if (_is_first(i) || _is_middle(i, argc))
			close(pfd_pp[i][1]);

		i++;
	}
	return (0);
}
