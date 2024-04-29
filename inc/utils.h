/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:38:42 by yliu              #+#    #+#             */
/*   Updated: 2024/04/28 14:31:11 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "ft_printf.h"
# include "libft.h"
# include <string.h>
# include <sys/errno.h>
# include <unistd.h>

# ifndef FAIL
#  define FAIL -1
# endif
# define CMD_NOT_FOUND "command not found"

typedef enum e_exit_status
{
	NOT_EXECUTABLE = 126,
	NO_FILE_OR_CMD_ERR = 127
}			t_exit_status;

// error.c
int			print_error(const char *basename, char *str, int exit_status);
int			print_errno(const char *errno_msg);
int			print_quote_error(void);

// utils.c
const char	*search_path_list(const char *envp[]);
bool		is_basename_has_slash(const char *basename);
char		**lst_2_char(t_lst **lst_pp);

#endif
