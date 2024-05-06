/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 21:50:55 by yliu              #+#    #+#             */
/*   Updated: 2024/05/06 18:09:47 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HERE_DOC_H
# define HERE_DOC_H

# include "get_next_line.h"
# include "libft.h"
# include "xwrapper.h"

typedef struct s_fd		t_fd;
typedef struct s_arg	t_arg;

int						is_heredoc(const char **argv);
int						open_heredoc_fd(const char *limiter, int **fd_info,
							int cmd_num);

#endif
