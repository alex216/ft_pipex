/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 21:50:30 by yliu              #+#    #+#             */
/*   Updated: 2024/05/05 14:57:00 by yliu             ###   ########.fr       */
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

int	open_heredoc_fd(const char *limiter)
{
	int		pipefd[2];
	char	*line;
	char	*limiter_nl;

	xpipe(pipefd);
	limiter_nl = ft_strjooin(2, limiter, "\n");
	while (1)
	{
		write(STDERR_FILENO, "> ", 2);
		line = get_next_line(STDIN_FILENO);
		if (!ft_strcmp(line, limiter_nl))
			break ;
		write(pipefd[1], line, ft_strlen(line));
		free(line);
	}
	free(line);
	free(limiter_nl);
	close(pipefd[1]);
	return (pipefd[0]);
}
