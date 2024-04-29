/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 20:49:32 by yliu              #+#    #+#             */
/*   Updated: 2024/04/29 18:15:10 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"
#include "ft_double_linked_list.h"
#include "ft_str.h"
#include "parse_string.h"

static void	concate_token(void *void_p)
{
	char		*a;
	char		*b;
	t_record	*record_p;
	t_lst		*lst_p;

	lst_p = (t_lst *)void_p;
	a = get_char_of(lst_p);
	b = get_char_of(lst_p->next_p);
	record_p = (lst_p->payload_p);
	record_p->str = ft_strjooin(2, a, b);
	record_p->length = record_p->length + (lst_p->next_p->payload_p->length);
	ft_dl_lstdelone(lst_p->next_p, *del);
}

static bool	should_concat(const t_lst *lst_p)
{
	return (lst_p->payload_p->type != BLANK
		&& lst_p->next_p->payload_p->type != BLANK);
}

const char	**parse_string(const char *cmd)
{
	t_lst	*lst_p;

	lst_p = parse_string_by_blank(cmd);
	ft_dl_lstmap(&lst_p, *remove_quote);
	ft_dl_lstreduce(&lst_p, *should_concat, *concate_token);
	ft_dl_lstfilter(&lst_p, *is_node_token, *del);
	return ((const char **)lst_2_char(&lst_p));
}
