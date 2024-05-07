/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 13:18:48 by yliu              #+#    #+#             */
/*   Updated: 2024/05/07 21:45:33 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_helper.h"

static int	_open_infile_fd(const char *filename)
{
	int	fd;

	xaccess_is_f_ok(filename);
	fd = open(filename, O_RDONLY | O_CLOEXEC);
	if (fd == FAIL)
		exit(print_error(filename, strerror(PERMISSION_DENIED), 1));
	return (fd);
}

static int	_open_created_outfile_fd(const char *filename)
{
	int	fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC | O_CLOEXEC, 0644);
	if (fd == FAIL)
		exit(print_error(filename, strerror(errno), 1));
	return (fd);
}

static int	_open_appended_outfile_fd(const char *filename)
{
	int	fd;

	fd = open(filename, O_WRONLY | O_APPEND | O_CREAT | O_CLOEXEC, 0644);
	if (fd == FAIL)
		exit(print_error(filename, strerror(errno), 1));
	return (fd);
}

void	open_pipes(int cmd_i, int **pipefd, t_arg *arg_info, t_fd *fd_info)
{
	const char	**argv;
	int			cmd_num;
	int			argc;

	argv = arg_info->argv;
	argc = arg_info->argc;
	cmd_num = arg_info->cmd_num;
	if (is_first(cmd_i) || is_middle(cmd_i, cmd_num))
		xpipe(pipefd[cmd_i]);
	if (is_first(cmd_i))
	{
		if (arg_info->is_heredoc)
			fd_info->infile_fd = open_heredoc_fd(argv[2], pipefd,
					arg_info->cmd_num);
		else
			fd_info->infile_fd = _open_infile_fd(argv[1]);
	}
	if (is_last(cmd_i, cmd_num))
	{
		if (arg_info->is_heredoc)
			fd_info->outfile_fd = _open_appended_outfile_fd(argv[argc - 1]);
		else
			fd_info->outfile_fd = _open_created_outfile_fd(argv[argc - 1]);
	}
}
