/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_string_extract.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:08:03 by yliu              #+#    #+#             */
/*   Updated: 2024/04/28 15:29:05 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_double_linked_list.h"
#include "parse_string.h"

void	extract_single_quotated_area(const char *cmd, int *p, t_lst **lst_pp)
{
	int	token_len;

	token_len = 1;
	while (!is_s_quote_end(cmd + token_len, *p))
	{
		if (cmd[*p + token_len] == '\0')
			exit(print_quote_error());
		token_len++;
	}
	append_str(lst_pp, ft_substr(cmd, *p, token_len + 1), QUOTE);
	*p += token_len + 1;
}

void	extract_non_quoted_area(const char *cmd, int *p, t_lst **lst_pp)
{
	int	token_len;

	token_len = 0;
	while (cmd[*p + token_len] && !is_sep(cmd, *p + token_len))
		token_len++;
	append_str(lst_pp, ft_substr(cmd, *p, token_len), OTHERS);
	*p += token_len;
}

void	extract_blank_token_area(const char *cmd, int *p, t_lst **lst_pp)
{
	int	token_len;

	token_len = 0;
	while (ft_isblank(cmd[*p + token_len]))
		token_len++;
	append_str(lst_pp, ft_substr(cmd, *p, token_len), BLANK);
	*p += token_len;
}
