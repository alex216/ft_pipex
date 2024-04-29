/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_string_helper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:01:34 by yliu              #+#    #+#             */
/*   Updated: 2024/04/29 18:17:05 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_string.h"

bool	is_sep(const char *cmd, int position)
{
	return (ft_isblank(cmd[position]) || is_s_quote_start(cmd, position));
}

bool	is_backslash_quoted(const char *src, int pos)
{
	int	back_slash_num;

	if (pos == 0)
		return (false);
	else
	{
		pos--;
		back_slash_num = 0;
		while (pos >= 0 && src[pos] == '\\')
		{
			if (src[pos] == '\\')
				back_slash_num++;
			pos--;
		}
		return (back_slash_num % 2);
	}
}

bool	is_s_quote_start(const char *cmd, int position)
{
	if (cmd[position] == S_QUOTE)
		return (!is_backslash_quoted(cmd, position));
	else
		return (false);
}

bool	is_s_quote_end(const char *cmd, int position)
{
	return (cmd[position] == S_QUOTE);
}
