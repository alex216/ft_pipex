/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 09:26:06 by yliu              #+#    #+#             */
/*   Updated: 2024/05/04 09:40:04 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	return_infile_fd(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == FAIL)
		exit(print_error(filename, strerror(PERMISSION_DENIED), 1));
	return (fd);
}

static int	return_outfile_fd(const char *filename)
{
	int	fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == FAIL)
		exit(print_error(filename, strerror(errno), 1));
	return (fd);
}

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
