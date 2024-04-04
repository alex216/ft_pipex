/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:29:58 by yliu              #+#    #+#             */
/*   Updated: 2024/04/04 18:18:39 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "utils.h"

void	free_list(void **list)
{
	int	i;

	i = 0;
	while (list[i])
		free(list[i++]);
	free(list);
}

char	*strjooin(int argc, const char *a, const char *b, ...)
{
	const char	*tmp;
	char		*tmp2;
	char		*ans;
	va_list		ap;
	int			i;

	va_start(ap, b);
	ans = ft_strjoin(a, b);
	i = 2;
	while (i < argc)
	{
		tmp = va_arg(ap, const char *);
		tmp2 = ft_strjoin(ans, tmp);
		free(ans);
		ans = ft_strdup(tmp2);
		free(tmp2);
		i++;
	}
	va_end(ap);
	return (ans);
}

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
