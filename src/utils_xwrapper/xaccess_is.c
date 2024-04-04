/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xaccess_is.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:33:58 by yliu              #+#    #+#             */
/*   Updated: 2024/04/04 16:34:11 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "utils.h"
#include <stdio.h>

bool	xaccess_is_f_ok(const char *name)
{
	if (access(name, F_OK) != SUCCESS)
		exit(print_error(name, strerror(ENOENT), NO_FILE_OR_CMD_ERR));
	return (true);
}

bool	xaccess_is_f_ok_alt(const char *name)
{
	if (access(name, F_OK) != SUCCESS)
		exit(print_error(name, CMD_NOT_FOUND, NO_FILE_OR_CMD_ERR));
	return (true);
}

bool	xaccess_is_x_ok(const char *name)
{
	if (access(name, X_OK) != SUCCESS)
		exit(print_error(name, strerror(EACCES), NOT_EXECUTABLE));
	return (true);
}
