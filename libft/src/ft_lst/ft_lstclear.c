/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 23:05:42 by yliu              #+#    #+#             */
/*   Updated: 2024/01/11 11:54:32 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst_pp, void (*del)(void *))
{
	t_list	*iter_p;
	t_list	*tmp_p;

	if (lst_pp == NULL || del == NULL)
		return ;
	if (*lst_pp == NULL)
		return ;
	iter_p = *lst_pp;
	while (iter_p != NULL)
	{
		tmp_p = iter_p->next;
		ft_lstdelone(iter_p, del);
		iter_p = tmp_p;
	}
	*lst_pp = NULL;
}
