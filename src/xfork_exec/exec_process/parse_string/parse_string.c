/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 20:49:32 by yliu              #+#    #+#             */
/*   Updated: 2024/05/04 10:41:58 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"
#include "ft_double_linked_list.h"
#include "ft_str.h"
#include "parse_string.h"

const char	**parse_string(const char *cmd)
{
	t_lst	*lst_p;
	const char **ans;

	lst_p = parse_string_by_blank(cmd);
	ft_dl_lstmap(&lst_p, *remove_quote);
	ft_dl_lstreduce(&lst_p, *should_concat_token, *concate_token);
	ft_dl_lstfilter(&lst_p, *is_node_token, *del);
	ans = (const char **)lst_2_char(&lst_p);
	ft_dl_lstclear(&lst_p, *del);
	return (ans);
}
