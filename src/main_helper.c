/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 09:26:06 by yliu              #+#    #+#             */
/*   Updated: 2024/05/04 09:26:50 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_arg_info(int argc, const char **argv, const char **envp,
		t_arg *arg_info)
{
	arg_info->argv = argv;
	arg_info->argc = argc;
	arg_info->envp = envp;
}

void	init_fd_info(int argc, const char **argv, t_fd *fd_info)
{
	fd_info->infile_fd = return_infile_fd(argv[1]);
	fd_info->outfile_fd = return_outfile_fd(argv[argc - 1]);
}

bool is_first(int cmd_num)
{
	return (cmd_num == 0);
}

bool	is_last(int cmd_num, int argc)
{
	return (cmd_num == argc - 4);
}

bool	is_middle(int cmd_num, int argc)
{
	return (cmd_num > 0 && cmd_num < argc - 4);
}
