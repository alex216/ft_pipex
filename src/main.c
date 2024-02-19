/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:57:53 by yliu              #+#    #+#             */
/*   Updated: 2024/02/19 14:53:12 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "pipex.h"

// no free because this func is for exeve.
char	*_create_absolute_cmd_name(char *cmd_name)
{
	// char *path_adr;
	// check if environ++ is allowed.

	int	i;
	char	**m_cmds;
	char	*first = ft_strjoin("/", cmd_name);
	const char	sep_string[] = "PATH=";

	i = 0;
	while (environ[i])
	{
		if (!strncmp(environ[i], sep_string, ft_strlen(sep_string)))
			break;
		i++;
	}
	m_cmds = ft_split(environ[i] + ft_strlen(sep_string), ':');
	int j = 0;
	char	*second;
	while (m_cmds[j])
	{
		second = ft_strjoin(m_cmds[j], first);
		if (access(second, F_OK | X_OK) == 0)
			break;
		j++;
	}
	return (second);

}

// since this is not multi-thread process,
// alloc is safe to use.
void	_exec_child(char *cmd, int pipefd[])
{
	char	**cmdstr;
	char	*cmd_full_path;

	cmdstr = ft_split(cmd, ' ');
	cmd_full_path = _create_absolute_cmd_name(*cmdstr);
	redirect_fd(pipefd[1], STDOUT_FILENO);
	close(pipefd[0]);
	execve(cmd_full_path, cmdstr, environ);
	// exit_errno_msg(strerror(errno))
	// _exit(EXIT_FAILURE);
}

// since this is not multi-thread process,
// alloc is safe to use.
void	_exec_parent(char *cmd, int pipefd[])
{
	char	**cmdstr;
	char	*cmd_full_path;

	cmdstr = ft_split(cmd, ' ');
	cmd_full_path = _create_absolute_cmd_name(*cmdstr);
	redirect_fd(pipefd[0], STDIN_FILENO);
	close(pipefd[1]);
	execve(cmd_full_path, cmdstr, environ);
	// perror("execve");
	// exit(EXIT_FAILURE);
}


__attribute__((destructor))void	destructor(void)
{
	system("leaks a.out");
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		pipefd[2];
	char	*cmd;
	char	*cmd2;

	// TODO: should inpliment popen, pclose ?
	// TODO: whatif ls and wc is reversed in pid
	// TODO: wrapper func of dup, close, pipe, fork and etc
	// TODO: create popen-like func
	// 			int	mock-popen(const char *command, const char *mode);
	if (argc != 5)
		exit(42);
	cmd = argv[2];
	cmd2 = argv[3];
	if (pipe(pipefd) == FAIL)
		exit_errno_msg(strerror(errno));
	pid = fork();
	if (pid == FAIL)
		exit_errno_msg(strerror(errno));
	if (pid == CHILD)
		_exec_child(cmd, pipefd);
	else
		_exec_parent(cmd2, pipefd);
	return (0);
}
