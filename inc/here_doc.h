/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 21:50:55 by yliu              #+#    #+#             */
/*   Updated: 2024/05/08 11:50:54 by yliu             ###   ########.fr       */
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
char					*heredoc_file(const char *limiter, t_arg *arg_info);

#endif
