/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:57:53 by yliu              #+#    #+#             */
/*   Updated: 2024/05/08 09:49:32 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	_alloc_pipes(int ***pipefd, int size)
{
	int	i;

	*pipefd = ft_xcalloc(sizeof(int *) * size);
	i = 0;
	while (i < size)
	{
		(*pipefd)[i] = ft_xcalloc(sizeof(int) * 2);
		i++;
	}
}

static void	_free_pipes(int **pipefd, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(pipefd[i]);
		i++;
	}
	free(pipefd);
}

int	main(int argc, const char **argv, const char **envp)
{
	t_arg	arg_info;
	t_fd	fd_info;
	int		**pipefd;

	if (argc < 5 || (argc < 6 && is_heredoc(argv)))
		exit(0);
	init_arg_info(argc, argv, envp, &arg_info);
	_alloc_pipes(&pipefd, arg_info.cmd_num - 1);
	loop_xfork(&arg_info, &fd_info, pipefd);
	_free_pipes(pipefd, arg_info.cmd_num - 1);
	return (0);
}
