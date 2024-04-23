/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 20:49:32 by yliu              #+#    #+#             */
/*   Updated: 2024/04/23 20:06:57 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "parse_string.h"
#include "pipex.h"
#include "util.h"
#include "utils.h"

static void	_append_str(t_lst **lst_pp, const char *str)
{
	ft_dl_lstadd_back_with_lst(lst_pp, create_lst_node(str));
}

static t_lst	**parse_string_by_blank(const char *cmd)
{
	int	token_len;
	int	pos;
	t_lst	**lst_pp;

	pos = 0;
	*lst_pp = NULL;
	while (cmd[pos])
	{
		if (ft_isblank(cmd[pos]))
			pos++;
		token_len = 0;
		while (cmd[pos + token_len] && !ft_isblank(cmd[pos + token_len]))
			token_len++;
		_append_str(lst_pp, ft_substr(cmd, pos, token_len));
		pos += token_len;
	}
	return (lst_pp);
}

static char	**_lst_2_char(t_lst *lst_p)
{
	int			i;
	char	**ans;

	i = 0;
	ans = ft_xcalloc(sizeof(char *) * (ft_dl_lstsize(lst_p) + 1));
	while (!lst_p->is_sentinel)
	{
		ans[i] = return_printable(lst_p);
		lst_p = lst_p->next_p;
		i++;
	}
	return (ans);
}

const char	**parse_string(const char *cmd)
{
	t_lst	**lst_pp;
	char	**ans;

	lst_pp = parse_string_by_blank(cmd);
	ans = (char **)_lst_2_char(*lst_pp);
	return ((const char **)ans);
}
