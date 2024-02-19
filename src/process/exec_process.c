/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:06:36 by yliu              #+#    #+#             */
/*   Updated: 2024/02/19 18:10:40 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// no free because this func is for exeve.
static const char	*_create_cmd_full_path(const char *cmd_first_string)
{
	static const char	sep_string[] = "PATH=";
	char				**path_list;
	const char			*full_path;

	if (ft_strchr(cmd_first_string, '/'))
		return (cmd_first_string);
	while (environ)
	{
		if (!strncmp(*environ, sep_string, ft_strlen(sep_string)))
			break ;
		environ++;
	}
	path_list = ft_split(*environ + ft_strlen(sep_string), ':');
	while (*path_list)
	{
		full_path = ft_strjoin(*path_list, ft_strjoin("/", cmd_first_string));
		if (access(full_path, F_OK | X_OK) == 0)
			break ;
		path_list++;
	}
	return (full_path);
}

// since this is not multi-thread process,
// alloc is safe to use.
void	exec_process(const char *arg_str)
{
	t_command	cmd;

	cmd.all_string = ft_split(arg_str, ' ');
	cmd.full_path = _create_cmd_full_path(*cmd.all_string);
	execve(cmd.full_path, cmd.all_string, environ);
	exit_errno_msg(strerror(errno));
}
