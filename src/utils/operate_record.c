/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_record.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:47:58 by yliu              #+#    #+#             */
/*   Updated: 2024/04/23 19:17:18 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex.h"
#include "util.h"
#include "parse_string.h"
#include "utils.h"

static void	*_creat_record(const char *str)
{
	t_record	*token_p;

	token_p = ft_xcalloc(sizeof(t_record));
	token_p->str = ft_strdup(str);
	token_p->length = ft_strlen(str);
	return (token_p);
}

t_lst	*create_lst_node(const char *str)
{
	t_lst	*lst_p;

	lst_p = ft_xcalloc(sizeof(t_lst));
	lst_p->payload_p = _creat_record(str);
	lst_p->is_sentinel = false;
	lst_p->next_p = NULL;
	lst_p->prev_p = NULL;
	return (lst_p);
}

void	free_record(t_record *token_p)
{
	free(token_p->str);
	free(token_p);
}
