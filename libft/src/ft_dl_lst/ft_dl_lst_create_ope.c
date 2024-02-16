/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_lst_create_ope.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:04:09 by yliu              #+#    #+#             */
/*   Updated: 2024/02/15 10:59:14 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	ft_dl_lstadd_sentinel_to_node(t_lst *lst_pp)
{
	t_lst	*sentinel_p;

	sentinel_p = ft_dl_lstcreate_a_node(NULL, true);
	if (!sentinel_p)
		return (false);
	lst_pp->next_p = sentinel_p;
	lst_pp->prev_p = sentinel_p;
	sentinel_p->next_p = lst_pp;
	sentinel_p->prev_p = lst_pp;
	return (true);
}

bool	ft_dl_lstadd_back_with_lst(t_lst **lst_pp, t_lst *new_p)
{
	t_lst	*sentinel_p;

	if (!new_p || !lst_pp)
		return (false);
	if (!*lst_pp)
	{
		if (!ft_dl_lstadd_sentinel_to_node(new_p))
			return (false);
		*lst_pp = new_p;
	}
	else
	{
		sentinel_p = (*lst_pp)->prev_p;
		new_p->prev_p = sentinel_p->prev_p;
		new_p->next_p = sentinel_p;
		sentinel_p->is_sentinel++;
		sentinel_p->prev_p->next_p = new_p;
		sentinel_p->prev_p = new_p;
	}
	return (true);
}

bool	ft_dl_lstadd_front_with_lst(t_lst **lst_pp, t_lst *new_p)
{
	if (!new_p || !lst_pp)
		return (false);
	if (!*lst_pp)
	{
		if (!ft_dl_lstadd_sentinel_to_node(new_p))
			return (false);
		*lst_pp = new_p;
	}
	else
	{
		new_p->prev_p = (*lst_pp)->prev_p;
		new_p->next_p = *lst_pp;
		(*lst_pp)->prev_p->is_sentinel++;
		(*lst_pp)->prev_p->next_p = new_p;
		(*lst_pp)->prev_p = new_p;
		*lst_pp = new_p;
	}
	return (true);
}

bool	ft_dl_lstappend(t_lst **lst_pp, t_record *record_p)
{
	t_lst	*lst_p;

	if (!record_p || !lst_pp)
		return (false);
	lst_p = ft_dl_lstcreate_a_node(record_p, false);
	if (!lst_p)
		return (false);
	if (!*lst_pp)
	{
		if (!ft_dl_lstadd_sentinel_to_node(lst_p))
			return (false);
		*lst_pp = lst_p;
	}
	else
	{
		if (!ft_dl_lstadd_back_with_lst(lst_pp, lst_p))
			return (false);
	}
	return (true);
}

// exit becase ans_pp is created inside this func.
// t_lst	*ft_dl_lstdup(t_lst **src_pp)
// {
// 	t_lst	*iter_p;
// 	t_lst	*des_p;
// 	t_lst	*iter_cpy_p;
// 	t_record	*record_p;
//
// 	des_p = NULL;
// 	if (!src_pp)
// 		return (NULL);
// 	if (!*src_pp)
// 		return (NULL);
// 	iter_p = *src_pp;
// 	while (!iter_p->is_sentinel)
// 	{
// 		record_p = create_record(iter_p->payload_p->char_content);
// 		if (!record_p)
// 			exit(EXIT_FAILURE);
// 		// record_p->index = get_index_of(iter_p);
// 		iter_cpy_p = ft_dl_lstcreate_a_node(record_p, false);
// 		if (!iter_cpy_p)
// 			exit (EXIT_FAILURE);
// 		if (!ft_dl_lstadd_back_with_lst(&des_p, iter_cpy_p))
// 			exit(EXIT_FAILURE);
// 		iter_p = iter_p->next_p;
// 	}
// 	return (des_p);
// }
