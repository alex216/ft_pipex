/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 09:26:06 by yliu              #+#    #+#             */
/*   Updated: 2024/05/05 13:07:21 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_helper.h"

void	init_arg_info(int argc, const char **argv, const char **envp,
		t_arg *arg_info)
{
	arg_info->argv = argv;
	arg_info->argc = argc;
	arg_info->envp = envp;
	arg_info->is_heredoc = is_heredoc(argv);
	arg_info->cmd_num = argc - 3 - arg_info->is_heredoc;
}
