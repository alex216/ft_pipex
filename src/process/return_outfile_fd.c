/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_outfile_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:04:47 by yliu              #+#    #+#             */
/*   Updated: 2024/02/19 18:04:55 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	return_outfile_fd(const char *filename)
{
	// need executable for bash
	// many flags to explore
	int fd;

	fd = open(filename, O_WRONLY);
	if (fd == FAIL)
		exit_errno_msg(strerror(errno));
	return (fd);
}

