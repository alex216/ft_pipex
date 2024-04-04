/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:29:58 by yliu              #+#    #+#             */
/*   Updated: 2024/04/04 12:24:24 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "utils.h"
#include <stdio.h>

int	dprint_with_bash_colon(const char *basename, char *str, int exit_status)
{
	ft_dprintf(STDERR_FILENO, "bash: %s: %s\n", basename, str);
	return (exit_status);
}

void	exit_errno_msg(const char *errno_msg)
{
	ft_dprintf(STDERR_FILENO, "%s\n", errno_msg);
	exit(1);
}

void	free_list(void **list)
{
	int i;

	i = 0;
	while (list[i])
		free(list[i++]);
	free(list);
}