/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_infile_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:06:16 by yliu              #+#    #+#             */
/*   Updated: 2024/02/19 18:06:23 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	return_infile_fd(const char *filename)
{
	// need executable for bash
	// many flags to explore
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd == FAIL)
		exit_errno_msg(strerror(errno));
	return (fd);
}
