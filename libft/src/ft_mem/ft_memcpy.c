/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:59:49 by yliu              #+#    #+#             */
/*   Updated: 2024/01/11 11:54:33 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*tmp;

	if (dst == NULL || src == NULL)
		return (NULL);
	tmp = dst;
	while (n--)
		*(char *)tmp++ = *(char *)src++;
	return (dst);
}
