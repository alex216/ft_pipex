/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_calculate_len_utils.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:14:14 by yliu              #+#    #+#             */
/*   Updated: 2024/01/11 12:01:27 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_calculate_str_len(char *str, struct s_main *t_info)
{
	if (str == NULL)
		t_info->prt_len += NULL_LEN;
	else
		t_info->prt_len += ft_strlen(str);
}

void	pf_calculate_long_len(long long ll, char c, struct s_main *t_info)
{
	int	base;

	if (c == 'd' || c == 'i' || c == 'u')
		base = 10;
	if (c == 'x' || c == 'X')
		base = HEX_NUMBER;
	if (ll < 0)
	{
		ll = -ll;
		t_info->prt_len++;
	}
	if (ll / base)
		pf_calculate_long_len(ll / base, c, t_info);
	t_info->prt_len++;
}

void	pf_calculate_ull_len(unsigned long long ull, int base,
		struct s_main *t_info)
{
	if (ull < 0)
	{
		ull = -ull;
		t_info->prt_len++;
	}
	if (ull / base)
		pf_calculate_ull_len(ull / base, base, t_info);
	t_info->prt_len++;
}
