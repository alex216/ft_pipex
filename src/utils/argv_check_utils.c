/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_check_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 09:40:35 by yliu              #+#    #+#             */
/*   Updated: 2024/05/05 10:53:45 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

bool	is_first(int cmd_i)
{
	return (cmd_i == 0);
}

bool	is_last(int cmd_i, int cmd_num)
{
	return (cmd_i == cmd_num - 1);
}

bool	is_middle(int cmd_i, int cmd_num)
{
	return (cmd_i > 0 && cmd_i < cmd_num - 1);
}
