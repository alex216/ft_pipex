/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:16:51 by yliu              #+#    #+#             */
/*   Updated: 2024/05/05 13:20:45 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "dlist.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "here_doc.h"
# include "libft.h"
# include "main_helper.h"
# include "parse_string.h"
# include "utils.h"
# include "xfork_exec.h"
# include "xwrapper.h"
# include <fcntl.h>

int	main(int argc, const char **argv, const char *envp[]);

#endif
