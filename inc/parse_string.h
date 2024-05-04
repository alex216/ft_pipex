/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_string.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:15:47 by yliu              #+#    #+#             */
/*   Updated: 2024/05/04 10:33:33 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_STRING_H
# define PARSE_STRING_H

# include "dlist.h"
# include "ft_printf.h"
# include "libft.h"
# include "utils.h"

typedef enum e_char
{
	SPACE = 32,
	D_QUOTE = 34,
	S_QUOTE = 39,
	B_QUOTE = 92
}			t_char;

// concat_token.c
void	concate_token(void *void_p);

// remove_quote.c
void		remove_quote(void *lst_p);
t_lst		*parse_string_by_blank(const char *cmd);

// parse_string_helper.c
bool		is_sep(const char *cmd, int position);
bool		is_backslash_quoted(const char *cmd, int position);
bool		is_s_quote_start(const char *cmd, int position);
bool		is_s_quote_end(const char *cmd, int position);
bool		should_concat_token(const t_lst *lst_p);

// parse_string_extract.c
void		extract_single_quotated_area(const char *cmd, int *p,
				t_lst **lst_pp);
void		extract_non_quoted_area(const char *cmd, int *p, t_lst **lst_pp);
void		extract_blank_token_area(const char *cmd, int *p, t_lst **lst_pp);

// parse_string.c
const char	**parse_string(const char *cmd);
#endif
