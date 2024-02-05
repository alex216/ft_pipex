/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:57:53 by yliu              #+#    #+#             */
/*   Updated: 2024/02/05 18:38:52 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "pipex.h"

int	main(int argc, char **argv)
{
	int	i;

	ft_printf("argc is %d\n", argc);
	i = 0;
	while (i < argc)
		ft_printf("argv is %s\n", argv[i++]);
}
