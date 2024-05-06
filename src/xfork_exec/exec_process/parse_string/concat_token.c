/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concat_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 10:32:43 by yliu              #+#    #+#             */
/*   Updated: 2024/05/04 10:38:39 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_string.h"

void	concate_token(void *void_p)
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
	free(a);
	record_p->length = record_p->length + (lst_p->next_p->payload_p->length);
	ft_dl_lstdelone(lst_p->next_p, *del);
}
