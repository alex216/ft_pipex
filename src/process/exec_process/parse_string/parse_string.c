/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 20:49:32 by yliu              #+#    #+#             */
/*   Updated: 2024/04/04 18:41:29 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*_delete_backslash(char *str)
{
	char	*dst;
	char	*ans;

	dst = ft_xcalloc(ft_strlen(str));
	ans = dst;
	while (*str)
	{
		if (!(*str == '\\' && *(str + 1) == '"'))
			*dst++ = *str;
		str++;
	}
	return (ans);
}

char	*_return_if_empty_str(char *str)
{
	if (*str == '\0')
		return (NULL);
	return (str);
}

const char	*real_strchr(const char *str, char quote)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == quote && (i == 0 || str[i - 1] != '\\'))
			return (str + i);
		i++;
	}
	return (NULL);
}

const char	*real_strrchr(const char *str, char quote)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (i >= 0)
	{
		if (str[i] == quote && (i == (int)ft_strlen(str) - 1 || str[i - 1] != '\\'))
			return (str + i);
		i--;
	}
	return (NULL);
}

char	**_ret_string(const char *str, char quote)
{
	const char	*first;
	const char	*last;
	char		**stored_str;

	first = real_strchr(str, quote);
	last = real_strrchr(str, quote);
	stored_str = (char **)ft_xcalloc(sizeof(char *) * 4);
	stored_str[0] = _return_if_empty_str(ft_substr(str, 0, first - str));
	stored_str[1] = _return_if_empty_str(ft_substr(str, first - str + 1, last
				- (first + 1)));
	stored_str[2] = _return_if_empty_str(ft_substr(str, last - str + 1,
				ft_strlen(last)));
	stored_str[3] = NULL;
	return (stored_str);
}

const char	**parse_string(const char *str)
{
	int			i;
	char		**tmp;
	const char	*single_pos;
	const char	*double_pos;
	const char	**ans;
	char		*ttmp;

	single_pos = real_strchr(str, SINGLE_QUOTE);
	double_pos = real_strchr(str, DOUBLE_QUOTE);
	if (!single_pos && !double_pos)
		tmp = ft_split(str, SPACE);
	else if (single_pos && !double_pos)
		tmp = _ret_string(str, SINGLE_QUOTE);
	else if (double_pos && !single_pos)
		tmp = _ret_string(str, DOUBLE_QUOTE);
	else if (single_pos < double_pos)
		tmp = _ret_string(str, SINGLE_QUOTE);
	else
		tmp = _ret_string(str, DOUBLE_QUOTE);
	i = 0;
	while (tmp[i])
		i++;
	ans = ft_xcalloc(sizeof(char *) * (i + 1));
	i = 0;
	while (tmp[i])
	{
		ttmp = ft_strtrim(tmp[i], " ");
		ans[i] = _delete_backslash(ttmp);
		free(tmp[i]);
		free(ttmp);
		i++;
	}
	free(tmp);
	return ((const char **)ans);
}
