/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:35:16 by yliu              #+#    #+#             */
/*   Updated: 2024/04/28 15:06:56 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	print_error(const char *basename, char *str, int exit_status)
{
	ft_dprintf(STDERR_FILENO, "bash: %s: %s\n", basename, str);
	return (exit_status);
}

int	print_errno(const char *errno_msg)
{
	ft_dprintf(STDERR_FILENO, "%s\n", errno_msg);
	return (1);
}

int	print_quote_error(void)
{
	ft_dprintf(STDERR_FILENO, "quote>\n");
	return (1);
}
