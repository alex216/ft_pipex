/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:29:58 by yliu              #+#    #+#             */
/*   Updated: 2024/04/28 20:23:58 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"
#include "process.h"
#include "utils.h"

const char	*search_path_list(const char *envp[])
{
	while (*envp)
	{
		if (!strncmp(*envp, PATH, ft_strlen(PATH)))
			return (*envp);
		envp++;
	}
	return (NULL);
}

bool	is_basename_has_slash(const char *basename)
{
	return (ft_strchr(basename, '/'));
}

char	**lst_2_char(t_lst **lst_pp)
{
	int		i;
	t_lst	*lst_p;
	char	**ans;

	i = 0;
	lst_p = *lst_pp;
	ans = ft_xcalloc(sizeof(char *) * (ft_dl_lstsize(lst_p) + 1));
	while (!lst_p->is_sentinel)
	{
		if (get_type_of(lst_p) != BLANK)
			ans[i] = get_char_of(lst_p);
		lst_p = lst_p->next_p;
		i++;
	}
	return (ans);
}
