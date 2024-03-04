/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_infile_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:06:16 by yliu              #+#    #+#             */
/*   Updated: 2024/03/04 21:05:06 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	return_infile_fd(const char **argv, const char *filename)
{
	int	fd;

	// need executable for bash
	// many flags to explore
	fd = open(filename, O_RDONLY);
	if (fd == FAIL)
	{
		(void)argv;
		exit_with_perror(ft_strjoin("bash: ", filename));
	}
	return (fd);
}
