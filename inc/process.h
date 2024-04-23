/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:36:06 by yliu              #+#    #+#             */
/*   Updated: 2024/04/17 18:20:33 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_H
# define PROCESS_H

void		xclose(int fd);
void		xdup2(int dst, int src);
int			return_infile_fd(const char **argv, const char *filename);
int			return_outfile_fd(const char *outfile);
const char	*return_entire_path(const char *basename, const char *envp[]);
void		exec_process(const char *arg_str, const char *envp[]);
void		exec_child(const char **argv, const char *inflie, int pipefd[],
				const char *envp[]);
void		exec_parent(const char **argv, const char *outfile, int pipefd[],
				const char *envp[]);
#endif
