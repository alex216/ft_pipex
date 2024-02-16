/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:29:58 by yliu              #+#    #+#             */
/*   Updated: 2024/02/16 16:43:27 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	redirect_fd(int src, int dst)
{
	if (dup2(src, dst) == FAIL)
		exit_errno_msg(strerror(errno));
	if (close(src) == FAIL)
		exit_errno_msg(strerror(errno));
}

void	exit_errno_msg(char *errno_msg)
{
	ft_printf("%s\n", errno_msg);
	exit(42);
}

char	**xft_split(char *string)
{
	char	**m_string_pp;

	m_string_pp = ft_split(string, ' ');
	if (!m_string_pp)
		exit_errno_msg(strerror(errno));
	return (m_string_pp);
}
