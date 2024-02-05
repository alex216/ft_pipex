/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 11:49:37 by yliu              #+#    #+#             */
/*   Updated: 2024/01/11 11:54:47 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*ans;

	if (s == NULL)
		return (NULL);
	ans = NULL;
	i = 0;
	while (i < ft_strlen(s) + 1)
	{
		if (*(s + i) == (char)c)
			ans = (char *)(s + i);
		i++;
	}
	return (ans);
}
