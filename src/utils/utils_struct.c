/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:56:10 by yliu              #+#    #+#             */
/*   Updated: 2024/04/23 19:22:43 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*return_printable(const t_lst *lst_p)
{
	if (!lst_p)
		return (NULL);
	return (lst_p->payload_p->str);
}
