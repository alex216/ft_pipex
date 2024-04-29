/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_string_by_blank.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 22:35:39 by yliu              #+#    #+#             */
/*   Updated: 2024/04/28 22:35:49 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_string.h"

t_lst	*parse_string_by_blank(const char *cmd)
{
	int		p;
	t_lst	*lst_p;

	lst_p = NULL;
	p = 0;
	while (cmd[p])
	{
		if (ft_isblank(cmd[p]))
			extract_blank_token_area(cmd, &p, &lst_p);
		else if (is_s_quote_start(cmd, p))
			extract_single_quotated_area(cmd, &p, &lst_p);
		else
			extract_non_quoted_area(cmd, &p, &lst_p);
	}
	return (lst_p);
}
