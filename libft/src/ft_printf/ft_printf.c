/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:44:15 by yliu              #+#    #+#             */
/*   Updated: 2024/01/11 12:01:26 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	pf_process_int(char c, va_list *ap, struct s_main *t_info)
{
	int	i;

	i = va_arg(*ap, int);
	if (c == 'c')
	{
		ft_putchar_fd(i, STDOUT_FILENO);
		t_info->prt_len++;
	}
	if (c == 'd' || c == 'i')
	{
		ft_putnbr_fd(i, STDOUT_FILENO);
		pf_calculate_long_len((long)i, c, t_info);
	}
}

static void	pf_process_unsigned_int(char c, va_list *ap, struct s_main *t_info)
{
	unsigned int	un;

	un = va_arg(*ap, unsigned int);
	ft_putunbr_fd(un, STDOUT_FILENO, c);
	pf_calculate_long_len((long)un, c, t_info);
}

static void	pf_process_unsigned_ll(va_list *ap, struct s_main *t_info)
{
	unsigned long long	uli;

	uli = va_arg(*ap, unsigned long long);
	ft_putstr_fd("0x", STDOUT_FILENO);
	ft_putpointer_fd(uli, STDOUT_FILENO);
	t_info->prt_len += 2;
	pf_calculate_ull_len(uli, HEX_NUMBER, t_info);
}

static void	output_va(va_list *ap, const char c, struct s_main *t_info)
{
	char	*str;

	if (c == 's')
	{
		str = va_arg(*ap, char *);
		ft_putstr_fd(str, STDOUT_FILENO);
		pf_calculate_str_len(str, t_info);
	}
	if (c == 'c' || c == 'd' || c == 'i')
		pf_process_int(c, ap, t_info);
	if (c == 'u' || c == 'x' || c == 'X')
		pf_process_unsigned_int(c, ap, t_info);
	if (c == 'p')
		pf_process_unsigned_ll(ap, t_info);
	if (c == '%')
	{
		ft_putchar_fd('%', STDOUT_FILENO);
		t_info->prt_len++;
	}
}

int	ft_printf(const char *fmt, ...)
{
	va_list			ap;
	struct s_main	t_info;

	t_info.prt_len = 0;
	va_start(ap, fmt);
	while (*fmt != '\0')
	{
		if (*fmt == '%' && *(fmt + 1) != '\0' && ft_strchr(C_LIST, *(fmt + 1)))
			output_va(&ap, *++fmt, &t_info);
		else
		{
			ft_putchar_fd(*fmt, STDOUT_FILENO);
			t_info.prt_len++;
		}
		fmt++;
	}
	va_end(ap);
	return (t_info.prt_len);
}

// ////////////////////////////////////////// test func
//
//  __attribute__ ((destructor)) static void destructor()
//  {
//  	if (system("leaks -q a.out > /dev/null 2> /dev/null"))
//  		system("leaks -q a.out");
//  }
//
// #define TEST(fmt, ...){puts("---------");puts(fmt);
// 	printf(":%3d\n", printf(fmt, __VA_ARGS__));
// 	printf(":%3d\n", ft_printf(fmt, __VA_ARGS__));
// }
//
//  #include <stdio.h>
//  #include <limits.h>
//
//  int	main(void)
//  {
//  	printf(" %d\n",printf("hello world"));
//  	printf(" %d\n",ft_printf("hello world"));
//
//  	TEST("[%c]plle", 'a');
//  	TEST("[%c]p[%c]le", 'a', 'p');
//  	TEST("[%c]p[%c][%c][%c]", -2, 112, 0, 255);
//
//  	TEST("[%s]ple", "Ap");
//  	char	*sss = NULL;
//  	TEST("%s", sss);
//
//  	int a = 10;
//  	TEST("[%d]", a);
//  	TEST("[%d]", -23);
//  	TEST("[%d]", 42);
//  	TEST("[%d]", INT_MAX);
//  	TEST("[%d]", INT_MIN);
//  	// TEST("[%d]", INT_MAX + 1);
//  	// TEST("[%d]", INT_MIN - 1);
//
// 	int aa = 10;
// 	char	*z = NULL;
// 	TEST("[%p]", &aa);
// 	TEST("[%p]", &z);
// 	TEST("[%p]", NULL);
// 	// TEST("[%p]", -ULONG_MAX);
// 	// TEST("[%p]", LONG_MAX);
// 	// TEST("[%p]", LONG_MAX + 1);
// 	// TEST("[%p]", LONG_MIN);
// 	// TEST("[%p]", ULONG_MAX);
// 	//
//
//  	// TEST("[%u]", 32);
//  	// TEST("[%u]", 0);
//  	// TEST("[%u]", UINT_MAX);
//  	// TEST("[%u]", -1);
//  	// TEST("[%u]", -123423423);
//  	// //
//  	// TEST("[%X]", 0xbe);
//  	// TEST("[%X]", 220);
//   //
//  	// // TEST("[%x]", INT_MAX + 1);
//  	// // TEST("[%x]", INT_MAX + INT_MAX);
//  	// TEST("[%x]", -1);
//  	// TEST("[%x]", INT_MAX);
//  	// TEST("[%x]", -4);
//  	// TEST("[%x]", -2342);
//   //
//  	// printf(" %d\n",   printf("[%%fw0ewf%%23r2    %%%%]"));
//  	// printf(" %d\n",ft_printf("[%%fw0ewf%%23r2    %%%%]"));
//  //
//  // 	//// bonus
//  // 	//// TEST("[%#+000010x]", 238235);
//  // 	//// TEST("[%-0+10.3d]", 238235);
//  // 	//// TEST("[%#+10.3d]", 238235);
//  // 	//// TEST("[%4d]", a);
//  // 	//// printf("[%4x]\n", a);
//  // 	//// ft_printf("[%4x]\n", a);
//  // 	//// printf("[%.3d]\n", a);
//  // 	//// ft_printf("[%.3d]\n", a);
//  // 	//// printf("[%.3x]\n", a);
//  // 	//// ft_printf("[%.3x]\n", a);
//  // 	//// printf("[%4.3d]\n", a);
//  // 	//// ft_printf("[%4.3d]\n", a);
//  // 	//// printf("[%4.3x]\n", a);
//  // 	//// ft_printf("[%4.3x]\n", a);
//  // 	//// printf("[%*.*x]\n", 4, 3, a);
//  // 	//// ft_printf("[%*.*x]\n", 4, 3, a);
//  // 	//// int b = 100000;
//  // 	//// printf("[%4d]\n", b);
//  // 	//// ft_printf("[%4d]\n", b);
//  // 	//// printf("[%.3d]\n", b);
//  // 	//// ft_printf("[%.3d]\n", b);
//  // 	//// printf("[%4.3d]\n", b);
//  // 	//// ft_printf("[%4.3d]\n", b);
//  // 	return (0);
// }
