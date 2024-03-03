/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 20:49:32 by yliu              #+#    #+#             */
/*   Updated: 2024/03/03 15:53:06 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "pipex.h"

const char	*parse_point(const char *str, const char quote)
{
	const char *first;
	const char *last;

	first = ft_strchr(str, quote);
	last = ft_strrchr(str, quote);
	if (first == last)
		return (NULL);
	return(first);
}

const char **parse_string(const char *cmd_with_options)
{
	int i;
	const char **tmp;
	const char *single_quote_index;
	const char *double_quote_index;

	single_quote_index = parse_point(cmd_with_options, SINGLE_QUOTE);
	double_quote_index = parse_point(cmd_with_options, DOUBLE_QUOTE);

	if (!single_quote_index && !double_quote_index)						// no 2 quotes
		tmp = (const char **)ft_split(cmd_with_options, SPACE);
	else if (!single_quote_index && double_quote_index)					// double only
		tmp = (const char **)ft_split(cmd_with_options, DOUBLE_QUOTE);
	else if (single_quote_index && !double_quote_index)					// single only
		tmp = (const char **)ft_split(cmd_with_options, SINGLE_QUOTE);
	else if (single_quote_index < double_quote_index)					// single do
		tmp = (const char **)ft_split(cmd_with_options, SINGLE_QUOTE);
	else																// double do
		tmp = (const char **)ft_split(cmd_with_options, DOUBLE_QUOTE);
	i = 0;
	while (tmp[i])
	{
		tmp[i] = ft_strtrim(tmp[i], " ");
		// ft_dprintf(STDERR_FILENO, "##%s##\n", tmp[i]);
		i++;
	}
	return (tmp);
}
