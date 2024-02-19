/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:36:06 by yliu              #+#    #+#             */
/*   Updated: 2024/02/19 18:10:50 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_H
# define PROCESS_H

void	close_fd(int fd);
void	replace_fd(int dst, int src);
int	return_infile_fd(const char *infile);
int	return_outfile_fd(const char *outfile);
void	exec_process(const char *arg_str);
void	exec_child(const char *arg_str, const char *inflie, int pipefd[]);
void	exec_parent(const char *arg_str, const char *outfile, int pipefd[]);
#endif
