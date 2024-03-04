/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_infile_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:06:16 by yliu              #+#    #+#             */
/*   Updated: 2024/03/04 14:35:19 by yliu             ###   ########.fr       */
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
		// ft_dprintf(2,"%s: %s: %s\n",argv[0] + 2, argv[1], (strerror(errno)));
		exit_with_perror(ft_strjoin("bash: ", filename));
		exit(42);
	}
	return (fd);
}
