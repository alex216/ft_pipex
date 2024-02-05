/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 11:41:13 by yliu              #+#    #+#             */
/*   Updated: 2024/01/11 11:54:34 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	wc(char *str, char sep)
{
	size_t	words_count;
	size_t	i;

	i = 0;
	words_count = 0;
	while (str[i] != '\0')
	{
		if ((i == 0 && str[0] != sep) || (str[i] != sep && str[i - 1] == sep))
			words_count++;
		i++;
	}
	return (words_count);
}

static int	free_all(char **dst, size_t i)
{
	while (i > 0)
		free(dst[--i]);
	free(dst);
	return (false);
}

static int	ft_splitexec(char **dst, char const *str, char sep)
{
	size_t	word_len;
	size_t	i;

	i = 0;
	while (*str != '\0')
	{
		if (*str != sep)
		{
			word_len = 0;
			while (str[word_len] != '\0' && str[word_len] != sep)
				word_len++;
			dst[i] = ft_substr(str, 0, word_len);
			if (dst[i] == NULL)
				return (free_all(dst, i));
			i++;
			str = str + word_len;
		}
		else
			str++;
	}
	dst[i] = NULL;
	return (EXIT_SUCCESS);
}

char	**ft_split(char const *str, char sep)
{
	char	**dst;

	if (str == NULL)
		return (NULL);
	dst = malloc(sizeof(char *) * ((wc((char *)str, sep)) + 1));
	if (dst == NULL)
		return (NULL);
	if (ft_splitexec(dst, str, sep))
		return (NULL);
	return (dst);
}
