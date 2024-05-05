/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 13:46:22 by yliu              #+#    #+#             */
/*   Updated: 2024/05/05 13:50:45 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include <sys/errno.h>

# define CMD_NOT_FOUND "command not found"

typedef enum e_exit_status
{
	NOT_EXECUTABLE = 126,
	NO_FILE_OR_CMD_ERR = 127
}	t_exit_status;

int	print_error(const char *basename, char *str, int exit_status);
int	print_errno(const char *errno_msg);
int	print_quote_error(void);

#endif
