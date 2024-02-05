/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 22:53:53 by yliu              #+#    #+#             */
/*   Updated: 2024/01/11 11:54:32 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst_pp, t_list *new_p)
{
	t_list	*last_p;

	if (lst_pp == NULL || new_p == NULL)
		return ;
	if (*lst_pp == NULL)
		*lst_pp = new_p;
	else
	{
		last_p = ft_lstlast(*lst_pp);
		last_p->next = new_p;
	}
}
