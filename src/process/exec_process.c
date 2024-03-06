/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:06:36 by yliu              #+#    #+#             */
/*   Updated: 2024/03/05 16:20:54 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "pipex.h"
#include "utils.h"

// no free because this func is for exeve.
STATIC const char *_join_dir_base(const char **dirname_list,
	const char *basename)
{
	const char	*entire_path;

	while (*dirname_list)
	{
		char *tmp = ft_strjoin("/", basename);
		entire_path = ft_strjoin(*dirname_list, tmp);
		free(tmp);
		if (access(entire_path, F_OK | X_OK) == SUCCESS) // what if X_OK is not actually OK?
			return (entire_path);
		free((void *)entire_path);
		dirname_list++;
	}
	if (access(basename, F_OK | X_OK) == SUCCESS)
		return (ft_strjoin("./", basename));
	return (NULL);
}

STATIC const char *_search_path_list(const char *envp[])
{
	while (*envp)
	{
		if (!strncmp(*envp, PATH, ft_strlen(PATH)))
			return (*envp);
		envp++;
	}
	return (NULL);
}

// no free because this func is for exeve.
STATIC const char *_return_entire_path(const char *basename, const char *envp[])
{
	const char	**dirname_list;
	const char	*path_list;

	if (ft_strchr(basename, '/'))
	{
		if (access(basename, F_OK)  == SUCCESS)
		{
			if (access(basename, X_OK)  == SUCCESS)
				return (basename);
			else
				exit(dprint_exit_with_bash_str(basename, EACCES, NOT_EXECUTABLE));
		}
		else
			exit(dprint_exit_with_bash_str(basename, ENOENT, NO_FILE_OR_CMD_ERR));
	}
	else
	{
		path_list = _search_path_list(envp);
		if (!path_list)
			exit(dprint_exit_with_bash_str(basename, ENOENT, NO_FILE_OR_CMD_ERR));
		dirname_list = (const char **)ft_split(path_list + ft_strlen(PATH), ':');
		const char *ans = _join_dir_base(dirname_list, basename);
		int i = 0;
		while (dirname_list[i])
			free((void *)dirname_list[i++]);
		free((void *)dirname_list);
		return (ans);
	}
}

// since this is not multi-thread process,
// alloc is safe to use.
void	exec_process(const char *cmd_with_options, const char *envp[])
{
	t_command	cmd;

	cmd.sep_by_space = (const char **)parse_string(cmd_with_options);
	cmd.entire_path = _return_entire_path(*cmd.sep_by_space, envp);
	if (!cmd.entire_path)
	{
		ft_dprintf(STDERR_FILENO, "bash: %s: command not found\n", (const char *)*cmd.sep_by_space);
		exit(NO_FILE_OR_CMD_ERR);
	}
	execve(cmd.entire_path, (char *const *)cmd.sep_by_space, (char **)envp);
	exit_errno_msg(strerror(errno));
}
