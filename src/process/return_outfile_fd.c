/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_outfile_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:04:47 by yliu              #+#    #+#             */
/*   Updated: 2024/04/04 12:24:24 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	return_outfile_fd(const char *filename)
{
	int	fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == FAIL)
		exit(dprint_with_bash_colon(filename, strerror(errno), 1));
	return (fd);
}
