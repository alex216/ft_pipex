/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_infile_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:06:16 by yliu              #+#    #+#             */
/*   Updated: 2024/04/24 22:35:11 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

int	return_infile_fd(const char **argv, const char *filename)
{
	int	fd;

	(void)argv;
	fd = open(filename, O_RDONLY);
	if (fd == FAIL)
		exit(print_error(filename, strerror(PERMISSION_DENIED), 1));
	return (fd);
}
