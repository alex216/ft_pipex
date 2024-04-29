/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 22:33:40 by yliu              #+#    #+#             */
/*   Updated: 2024/04/29 17:45:39 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"
#include "parse_string.h"

static void	_remove_s_d_quote(t_lst *lst_p)
{
	t_record	*record_p;
	char		*src;

	src = get_char_of(lst_p);
	record_p = ((t_lst *)lst_p)->payload_p;
	record_p->str = ft_substr(src, 1, ft_strlen(src) - 2);
	record_p->length = record_p->length - 2;
	record_p->type = OTHERS;
}

static void	_remove_back_quote(t_lst *lst_p)
{
	int		pos;
	char	*src;
	char	*dst;

	src = get_char_of(lst_p);
	dst = src;
	pos = 0;
	while (src[pos])
	{
		if (src[pos] == '\\' && !is_backslash_quoted(src, pos))
			pos++;
		else
			*dst++ = src[pos++];
	}
	*dst = '\0';
}

void	remove_quote(void *lst_p)
{
	if (get_type_of(lst_p) == QUOTE)
		_remove_s_d_quote(lst_p);
	else if (get_type_of(lst_p) == OTHERS)
		_remove_back_quote(lst_p);
}
