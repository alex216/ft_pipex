/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_check_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 09:40:35 by yliu              #+#    #+#             */
/*   Updated: 2024/05/04 09:40:42 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

bool	is_first(int cmd_num)
{
	return (cmd_num == 0);
}

bool	is_last(int cmd_num, int argc)
{
	return (cmd_num == argc - 4);
}

bool	is_middle(int cmd_num, int argc)
{
	return (cmd_num > 0 && cmd_num < argc - 4);
}
