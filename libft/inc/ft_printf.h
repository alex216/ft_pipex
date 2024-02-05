/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:24:54 by yliu              #+#    #+#             */
/*   Updated: 2023/11/02 15:18:39 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

# define NULL_LEN 6
# define HEX_NUMBER 16

# define C_LIST "cspdiuxX%"
# define LOEWRCASE_HEX_ARRAY "0123456789abcdef"
# define UPPERCASE_HEX_ARRAY "0123456789ABCDEF"

struct		s_main
{
	size_t	prt_len;
};

int			ft_printf(const char *fmt, ...);

size_t		ft_strlen(const char *str);
char		*ft_strchr(const char *s, int c);

void		pf_calculate_ull_len(unsigned long long ull, int base,
				struct s_main *t_info);
void		pf_calculate_long_len(long long ll, char c, struct s_main *t_info);
void		pf_calculate_str_len(char *str, struct s_main *t_info);

void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putunbr_fd(unsigned int un, int fd, char c);
void		ft_putpointer_fd(unsigned long long n, int fd);

#endif
