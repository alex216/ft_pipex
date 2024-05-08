/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 21:50:30 by yliu              #+#    #+#             */
/*   Updated: 2024/05/08 11:50:20 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "here_doc.h"
#include "main_helper.h"

int	is_heredoc(const char **argv)
{
	if (!ft_strcmp(argv[1], "here_doc"))
		return (1);
	else
		return (0);
}

static char	*_randomized_filename(char *seed)
{
	char	*filename;
	int		n;

	n = (int)(unsigned long long)&seed;
	filename = ft_strjooin(2, ".heredoc_tmp_", ft_itoa(n));
	return (filename);
}

char	*heredoc_file(const char *limiter, t_arg *arg_info)
{
	char	*limiter_nl;
	char	*line;
	int		heredoc_fd;
	char	*filename;

	filename = _randomized_filename((char *)limiter);
	arg_info->heredoc_filename = filename;
	heredoc_fd = open(filename,
			O_WRONLY | O_CREAT | O_TRUNC | O_EXCL | O_CLOEXEC, 0644);
	limiter_nl = ft_strjooin(2, limiter, "\n");
	while (1)
	{
		write(STDERR_FILENO, "> ", 2);
		line = get_next_line(STDIN_FILENO);
		if (!ft_strcmp(line, limiter_nl))
			break ;
		write(heredoc_fd, line, ft_strlen(line));
		free(line);
	}
	close(heredoc_fd);
	free(line);
	free(limiter_nl);
	return (filename);
}
