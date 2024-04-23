/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:06:36 by yliu              #+#    #+#             */
/*   Updated: 2024/04/23 16:55:31 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "pipex.h"
#include "utils.h"

// since this is not multi-thread process,
// alloc is safe to use.
void	exec_process(const char *cmd_with_options, const char *envp[])
{
	t_command	cmd;

	cmd.sep_by_space = (const char **)parse_string(cmd_with_options);
	cmd.entire_path = return_entire_path(*cmd.sep_by_space, envp);
	execve(cmd.entire_path, (char *const *)cmd.sep_by_space, (char **)envp);
	exit(print_errno(strerror(errno)));
}
