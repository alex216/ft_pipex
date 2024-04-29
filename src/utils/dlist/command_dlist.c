/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_dlist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:47:58 by yliu              #+#    #+#             */
/*   Updated: 2024/04/24 11:16:22 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_string.h"
#include "utils.h"
#include <pipex.h>

static void	*_creat_record(const char *str, int type)
{
	t_record	*token_p;

	token_p = ft_xcalloc(sizeof(t_record));
	token_p->str = ft_strdup(str);
	token_p->length = ft_strlen(str);
	token_p->type = type;
	return (token_p);
}

t_lst	*create_lst_node(const char *str, int type)
{
	t_lst	*lst_p;

	lst_p = ft_xcalloc(sizeof(t_lst));
	lst_p->payload_p = _creat_record(str, type);
	lst_p->is_sentinel = false;
	lst_p->next_p = NULL;
	lst_p->prev_p = NULL;
	return (lst_p);
}

void	append_str(t_lst **lst_pp, const char *str, int type)
{
	ft_dl_lstadd_back_with_lst(lst_pp, create_lst_node(str, type));
}

void	del(void *lst_p)
{
	free(((t_lst *)lst_p)->payload_p->str);
	free(((t_lst *)lst_p)->payload_p);
}
