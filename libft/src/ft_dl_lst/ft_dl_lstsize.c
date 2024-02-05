/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_lstsize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:05:17 by yliu              #+#    #+#             */
/*   Updated: 2024/01/11 16:41:54 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_dl_lstsize(const t_lst *lst_p)
{
	if (lst_p == NULL)
		return (0);
	return (lst_p->prev_p->is_sentinel);
}

// //////////////////////////////////////////
// #include "../../inc/ft_printf.h"
// static void	*del(void *tmp)
// {
// 	free(tmp);
// 	return (NULL);
// }
//
// int	main(void)
// {
// 	t_lst	*origin_p;
// 	t_lst	*tmp_p;
// 	t_lst	*tmp1_p;
//
// 	origin_p = ft_dl_lstnew(42);
// 	tmp_p = ft_dl_lstcreate(2, 0);
// 	tmp1_p = ft_dl_lstcreate(4, 0);
// 	ft_dl_pf_lst(origin_p);
// 	ft_printf("[size]%d\n", ft_dl_lstsize(origin_p));
// 	ft_dl_lstadd_front(&origin_p, tmp_p);
// 	ft_dl_pf_lst(origin_p);
// 	ft_printf("[size]%d\n", ft_dl_lstsize(origin_p));
// 	ft_dl_lstadd_front(&origin_p, tmp1_p);
// 	ft_dl_pf_lst(origin_p);
// 	ft_printf("[size]%d\n", ft_dl_lstsize(origin_p));
//
// 	ft_dl_lstclear(&origin_p, (void *)del);
//
// 	return (0);
// }
