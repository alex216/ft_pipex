/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:29:58 by yliu              #+#    #+#             */
/*   Updated: 2024/03/05 15:19:29 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "pipex.h"
#include <stdio.h>

int	dprint_exit_with_bash_str(const char *basename, int err, int exit_status)
{
	ft_dprintf(STDERR_FILENO, "bash: %s: %s\n", basename, strerror(err));
	return (exit_status);
}

void	exit_errno_msg(const char *errno_msg)
{
	ft_dprintf(STDERR_FILENO, "%s\n", errno_msg);
	exit(1);
}

void	exit_with_perror(const char *errno_msg)
{
	perror(errno_msg);
	exit(1);
}
