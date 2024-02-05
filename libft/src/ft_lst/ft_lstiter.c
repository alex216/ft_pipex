/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 22:03:07 by yliu              #+#    #+#             */
/*   Updated: 2024/01/11 11:54:32 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst_p, void (*f)(void *))
{
	if (lst_p == NULL || f == NULL)
		return ;
	while (lst_p != NULL)
	{
		f(lst_p->content);
		lst_p = lst_p->next;
	}
}
