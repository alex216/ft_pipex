/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:06:36 by yliu              #+#    #+#             */
/*   Updated: 2024/02/24 20:13:37 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "pipex.h"

// no free because this func is for exeve.
STATIC const char *_join_dir_base(const char **dirname_list,
	const char *basename)
{
	const char	*entire_path;

	while (*dirname_list)
	{
		entire_path = ft_strjoin(*dirname_list, ft_strjoin("/", basename));
		if (access(entire_path, F_OK | X_OK) == SUCCESS)
			return (entire_path);
		dirname_list++;
	}
	return (NULL);
}

STATIC const char *_search_path_envp(const char *envp[],
	const char *sep_string)
{
	while (envp)
	{
		if (!strncmp(*envp, sep_string, ft_strlen(sep_string)))
			return (*envp);
		envp++;
	}
	return (NULL);
}

// no free because this func is for exeve.
STATIC const char *_return_cmd_entire_path(const char *basename,
	const char *envp[])
{
	const char	**dirname_list;
	const char	*path_list;

	if (ft_strchr(basename, '/'))
		return (basename);
	path_list = _search_path_envp(envp, "PATH=");
	// if (!envp_p) PATH doesn't exist
	dirname_list = (const char **)ft_split(path_list + ft_strlen("PATH="), ':');
	return (_join_dir_base(dirname_list, basename));
}

// since this is not multi-thread process,
// alloc is safe to use.
void	exec_process(const char *cmd_with_options, const char *envp[])
{
	t_command	cmd;

	cmd.sep_by_space = (const char **)ft_split(cmd_with_options, ' ');
	cmd.entire_path = _return_cmd_entire_path(*cmd.sep_by_space, envp);
	if (!cmd.entire_path)
	{
		ft_dprintf(STDERR_FILENO, "bash: %s: command not found\n", (const char *)*cmd.sep_by_space);
		exit(COMMAND_NOT_FOUND);
	}
	execve(cmd.entire_path, (char * const*)cmd.sep_by_space, (char **)envp);
	exit_errno_msg(strerror(errno));
}
