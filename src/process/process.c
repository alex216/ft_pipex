/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:34:24 by yliu              #+#    #+#             */
/*   Updated: 2024/02/19 16:37:16 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// no free because this func is for exeve.
static char	*_create_cmd_full_path(char *cmd_name)
{
	static const char	sep_string[] = "PATH=";
	char				**cmd_path_list;
	char				*cmd_full_path;

	while (environ)
	{
		if (!strncmp(*environ, sep_string, ft_strlen(sep_string)))
			break ;
		environ++;
	}
	cmd_path_list = ft_split(*environ + ft_strlen(sep_string), ':');
	while (*cmd_path_list)
	{
		cmd_full_path = ft_strjoin(*cmd_path_list, ft_strjoin("/", cmd_name));
		if (access(cmd_full_path, F_OK | X_OK) == 0)
			break ;
		cmd_path_list++;
	}
	return (cmd_full_path);
}

// since this is not multi-thread process,
// alloc is safe to use.
static void	_exec_process(char *arg_str)
{
	t_command	cmd;

	cmd.all_string = ft_split(arg_str, ' ');
	cmd.full_path = _create_cmd_full_path(*cmd.all_string);
	execve(cmd.full_path, cmd.all_string, environ);
	exit_errno_msg(strerror(errno));
}

void	exec_child(char *arg_str, int pipefd[])
{
	replace_fd(STDOUT_FILENO, pipefd[1]);
	close_fd(pipefd[0]);
	_exec_process(arg_str);
}

void	exec_parent(char *arg_str, int pipefd[])
{
	replace_fd(STDIN_FILENO, pipefd[0]);
	close_fd(pipefd[1]);
	_exec_process(arg_str);
}
