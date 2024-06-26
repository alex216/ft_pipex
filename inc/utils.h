/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:38:42 by yliu              #+#    #+#             */
/*   Updated: 2024/05/06 12:13:21 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "ft_printf.h"
# include "libft.h"
# include "xwrapper.h"
# include <string.h>
# include <unistd.h>

// utils.c
const char	*search_path_list(const char *envp[]);
bool		is_basename_has_slash(const char *basename);
char		**lst_2_char(t_lst **lst_pp);
const char	*return_cmd(const char **argv, int cmd_num, int is_heredoc);

// argv_check_utils.c
bool		is_first(int cmd_num);
bool		is_last(int cmd_num, int argc);
bool		is_middle(int cmd_num, int argc);

// pipe_utils.c
int			pipe_read_fd(int **pipe_fd, int i);
int			pipe_write_fd(int **pipe_fd, int i);

#endif
