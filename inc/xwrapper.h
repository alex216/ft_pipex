/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xwrapper.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:52:00 by yliu              #+#    #+#             */
/*   Updated: 2024/05/05 13:50:38 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XWRAPPER_H
# define XWRAPPER_H

# include "error.h"
# include <stdbool.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define SUCCESS 0
# define CHILD 0
# define PARENT 1
# ifndef FAIL
#  define FAIL -1
# endif

pid_t	xfork(void);
void	xclose(int fd);
void	xpipe(int *pipefd);
void	xdup2(int dst, int src);
bool	xaccess_is_x_ok(const char *name);
bool	xaccess_is_f_ok(const char *name);
bool	xaccess_is_f_ok_alt(const char *name);

#endif
