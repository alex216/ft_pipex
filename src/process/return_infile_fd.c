/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_infile_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:06:16 by yliu              #+#    #+#             */
/*   Updated: 2024/04/04 12:24:24 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	return_infile_fd(const char **argv, const char *filename)
{
	int	fd;

	(void)argv;
	fd = open(filename, O_RDONLY);
	if (fd == FAIL)
		exit(dprint_with_bash_colon(filename, strerror(PERMISSION_DENIED),
				1));
	return (fd);
}
