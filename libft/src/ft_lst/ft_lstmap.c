/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 21:56:54 by yliu              #+#    #+#             */
/*   Updated: 2024/01/11 11:54:32 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *old_p, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head_p;
	t_list	*prev_p;

	if (old_p == NULL || f == NULL || del == NULL)
		return (NULL);
	head_p = ft_lstnew(f(old_p->content));
	if (head_p == NULL)
		return (NULL);
	prev_p = head_p;
	old_p = old_p->next;
	while (old_p != NULL)
	{
		prev_p->next = ft_lstnew(f(old_p->content));
		if (prev_p->next == NULL)
		{
			ft_lstclear(&head_p, del);
			return (NULL);
		}
		prev_p = prev_p->next;
		old_p = old_p->next;
	}
	ft_lstlast(head_p)->next = NULL;
	return (head_p);
}
