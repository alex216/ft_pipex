/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 21:50:30 by yliu              #+#    #+#             */
/*   Updated: 2024/05/05 09:54:35 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "here_doc.h"

int	is_heredoc(const char **argv)
{
	if (!ft_strcmp(argv[1], "here_doc"))
		return (1);
	else
		return (0);
}

// int	return_heredoc_fd(const char *limiter)
// {
//
// }
