/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 21:50:30 by yliu              #+#    #+#             */
/*   Updated: 2024/05/04 22:47:12 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_str.h"
#include "here_doc.h"

int	is_heredoc(const char **argv)
{
	int	len;

	len = ft_strlen("here_doc");
	if (!ft_strncmp(argv[1], "here_doc", len) && argv[1][len] == '\0')
		return (1);
	else
		return (0);
}
