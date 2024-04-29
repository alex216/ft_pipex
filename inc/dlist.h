/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:45:41 by yliu              #+#    #+#             */
/*   Updated: 2024/04/28 19:31:02 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLIST_H
# define DLIST_H

# include "libft.h"
# include <stdbool.h>
# include <stddef.h>

typedef enum e_token_type
{
	BLANK = 1,
	QUOTE = 2,
	OTHERS = 3
}					t_token_type;

typedef struct s_record
{
	char			*str;
	size_t			length;
	t_token_type	type;
}					t_record;

// query_dlist.c
char				*get_char_of(const t_lst *lst_p);
int					get_type_of(const t_lst *lst_p);
bool				is_node_token(const t_lst *lst_p);

// command_dlist.c
t_lst				*create_lst_node(const char *str, int type);
void				append_str(t_lst **lst_pp, const char *str, int type);
void				del(void *lst_p);

#endif
