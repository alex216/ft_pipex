/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 09:26:06 by yliu              #+#    #+#             */
/*   Updated: 2024/05/05 11:10:23 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_helper.h"

static int	return_infile_fd(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == FAIL)
		exit(print_error(filename, strerror(PERMISSION_DENIED), 1));
	return (fd);
}

static int	return_created_outfile_fd(const char *filename)
{
	int	fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == FAIL)
		exit(print_error(filename, strerror(errno), 1));
	return (fd);
}

static int	return_appended_outfile_fd(const char *filename)
{
	int	fd;

	fd = open(filename, O_WRONLY | O_APPEND | O_TRUNC, 0644);
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
	arg_info->is_heredoc = is_heredoc(argv);
	arg_info->cmd_num = argc - 3 - arg_info->is_heredoc;
}

void	init_fd_info(t_arg *arg_info, t_fd *fd_info)
{
	int			argc;
	const char	**argv;

	argc = arg_info->argc;
	argv = arg_info->argv;
	if (arg_info->is_heredoc)
	{
		// fd_info->infile_fd = return_heredoc_fd(argv[2]);
		fd_info->outfile_fd = return_appended_outfile_fd(argv[argc - 1]);
	}
	else
	{
		fd_info->infile_fd = return_infile_fd(argv[1]);
		fd_info->outfile_fd = return_created_outfile_fd(argv[argc - 1]);
	}
}
