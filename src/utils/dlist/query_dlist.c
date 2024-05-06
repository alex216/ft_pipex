/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   query_dlist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:56:10 by yliu              #+#    #+#             */
/*   Updated: 2024/04/28 19:31:01 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

char	*get_char_of(const t_lst *lst_p)
{
	if (!lst_p)
		return (NULL);
	return (lst_p->payload_p->str);
}

int	get_type_of(const t_lst *lst_p)
{
	if (!lst_p)
		return (-1);
	return (lst_p->payload_p->type);
}

bool	is_node_token(const t_lst *lst_p)
{
	return (get_type_of(lst_p) != BLANK);
}
