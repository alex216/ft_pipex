/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:29:58 by yliu              #+#    #+#             */
/*   Updated: 2024/03/01 22:08:44 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdio.h>

void	exit_errno_msg(const char *errno_msg)
{
	ft_dprintf(STDERR_FILENO, "%s\n", errno_msg);
	exit(42);
}

void	exit_with_perror(const char *errno_msg)
{
	perror(errno_msg);
	exit(42);
}
