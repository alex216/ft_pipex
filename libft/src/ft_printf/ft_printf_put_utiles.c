/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put_utiles.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:42:55 by yliu              #+#    #+#             */
/*   Updated: 2024/01/11 12:01:27 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL)
		write(fd, "(null)", 6);
	else
		write(fd, s, ft_strlen(s));
}

void	ft_putnbr_fd(int n, int fd)
{
	int		sign;
	char	c;

	sign = 1;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		sign = -1;
	}
	if (n / 10)
		ft_putnbr_fd(n / 10 * sign, fd);
	c = n % 10 * sign + '0';
	ft_putchar_fd(c, fd);
}

void	ft_putunbr_fd(unsigned int un, int fd, char c)
{
	if (c == 'u')
	{
		if (un / 10)
			ft_putunbr_fd(un / 10, fd, c);
		ft_putchar_fd(un % 10 + '0', fd);
	}
	if (c == 'x')
	{
		if (un / HEX_NUMBER)
			ft_putunbr_fd(un / HEX_NUMBER, fd, c);
		ft_putchar_fd(LOEWRCASE_HEX_ARRAY[un % HEX_NUMBER], fd);
	}
	if (c == 'X')
	{
		if (un / HEX_NUMBER)
			ft_putunbr_fd(un / HEX_NUMBER, fd, c);
		ft_putchar_fd(UPPERCASE_HEX_ARRAY[un % HEX_NUMBER], fd);
	}
}

void	ft_putpointer_fd(unsigned long long n, int fd)
{
	if (n / HEX_NUMBER)
		ft_putpointer_fd(n / HEX_NUMBER, fd);
	ft_putchar_fd(LOEWRCASE_HEX_ARRAY[n % HEX_NUMBER], fd);
}
