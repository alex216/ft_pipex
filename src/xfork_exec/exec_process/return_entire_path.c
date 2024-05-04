/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_entire_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:52:14 by yliu              #+#    #+#             */
/*   Updated: 2024/05/04 13:00:15 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xfork_exec.h"

static const char	*_join_dir_base(char **dirname_list, const char *basename)
{
	const char	*entire_path;

	while (*dirname_list)
	{
		entire_path = ft_strjooin(3, *dirname_list, "/", basename);
		if (access(entire_path, F_OK) == SUCCESS)
		{
			xaccess_is_x_ok(entire_path);
			return (entire_path);
		}
		free((void *)entire_path);
		dirname_list++;
	}
	xaccess_is_f_ok_alt(basename);
	xaccess_is_x_ok(basename);
	return (ft_strjoin("./", basename));
}

const char	*return_entire_path(const char *basename, const char *envp[])
{
	const char	*path_list;
	char		**dirname_list;
	const char	*ans;

	if (is_basename_has_slash(basename))
	{
		xaccess_is_f_ok(basename);
		xaccess_is_x_ok(basename);
		return (basename);
	}
	else
	{
		path_list = search_path_list(envp);
		if (!path_list)
			exit(print_error(basename, strerror(ENOENT), NO_FILE_OR_CMD_ERR));
		dirname_list = ft_split(path_list + ft_strlen(PATH), ':');
		ans = _join_dir_base(dirname_list, basename);
		ft_free_list((void **)dirname_list);
		return (ans);
	}
}
