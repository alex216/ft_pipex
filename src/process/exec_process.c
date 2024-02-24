/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:06:36 by yliu              #+#    #+#             */
/*   Updated: 2024/02/24 08:34:33 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "pipex.h"

// no free because this func is for exeve.
STATIC const char *_return_complete_cmd_path(const char **path_list,
	const char *cmd_first_string)
{
	const char	*full_path;

	while (*path_list)
	{
		full_path = ft_strjoin(*path_list, ft_strjoin("/", cmd_first_string));
		if (access(full_path, F_OK | X_OK) == SUCCESS)
			return (full_path);
		path_list++;
	}
	ft_dprintf(STDERR_FILENO, "bash: %s: command not found\n", (const char *)cmd_first_string);
	// not exsiting other
	exit(41);
}

STATIC const char *_return_cmd_path_envp(const char *envp[],
	const char *sep_string)
{
	while (envp)
	{
		if (!strncmp(*envp, sep_string, ft_strlen(sep_string)))
			break ;
		envp++;
	}
	return (*envp);
}

// no free because this func is for exeve.
STATIC const char *_create_cmd_full_path(const char *cmd_first_string,
	const char *envp[])
{
	const char	**path_list;
	const char	*envp_p;
	const char	sep_string[] = "PATH=";

	if (ft_strchr(cmd_first_string, '/'))
		return (cmd_first_string);
	envp_p = _return_cmd_path_envp(envp, sep_string);
	path_list = (const char **)ft_split(envp_p + ft_strlen(sep_string), ':');
	return (_return_complete_cmd_path(path_list, cmd_first_string));
}

// since this is not multi-thread process,
// alloc is safe to use.
void	exec_process(const char *arg_str, const char *envp[])
{
	t_command	cmd;

	cmd.all_string = ft_split(arg_str, ' ');
	cmd.full_path = _create_cmd_full_path(*cmd.all_string, envp);
	execve(cmd.full_path, cmd.all_string, (char **)envp);
	exit_errno_msg(strerror(errno));
}
