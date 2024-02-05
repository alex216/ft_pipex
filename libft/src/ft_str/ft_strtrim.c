/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 11:26:44 by yliu              #+#    #+#             */
/*   Updated: 2024/01/11 11:54:48 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	asign_array_to_set(char const *set, unsigned char *used)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		used[(unsigned char)set[i]] = 1;
		i++;
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t			i;
	size_t			start;
	size_t			end;
	unsigned char	used[MAX_CHAR];

	if (s1 == NULL || set == NULL)
		return (NULL);
	ft_bzero(used, MAX_CHAR);
	asign_array_to_set(set, used);
	i = 0;
	while (s1[i] != '\0')
	{
		if (!used[(unsigned char)s1[i]])
			break ;
		i++;
	}
	start = i;
	end = i;
	while (s1[i] != '\0')
	{
		if (!used[(unsigned char)s1[i]])
			end = i;
		i++;
	}
	return (ft_substr(s1, start, end - start + 1));
}
