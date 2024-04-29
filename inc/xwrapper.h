/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xwrapper.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:52:00 by yliu              #+#    #+#             */
/*   Updated: 2024/04/25 10:13:00 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XWRAPPER_H
# define XWRAPPER_H

# include "utils.h"
# include <stdbool.h>

# define SUCCESS 0

void	xclose(int fd);
void	xdup2(int dst, int src);
bool	xaccess_is_x_ok(const char *name);
bool	xaccess_is_f_ok(const char *name);
bool	xaccess_is_f_ok_alt(const char *name);

#endif
