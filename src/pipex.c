/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejeon <yejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:41:28 by yejeon            #+#    #+#             */
/*   Updated: 2021/10/29 03:19:09 by yejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ps_1(int *fd_pipe, char **argv, char **envp)
{
	int	fd_input;

	fd_input = open(argv[1], O_RDONLY, 0777);
	if (-1 == fd_input)
		error_exit("ps_1 open");
	if (-1 == dup2(fd_input, STDIN_FILENO))
		error_exit("ps_1 dup2 STDIN_FILENO");
	if (-1 == dup2(fd_pipe[1], STDOUT_FILENO))
		error_exit("ps_1 dup2 STDOUT_FILENO");
	close(fd_pipe[0]);
	execute(argv[2], envp);
}

void	ps_2(int *fd_pipe, char **argv, char **envp)
{
	int	fd_output;

	fd_output = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (-1 == fd_output)
		error_exit("ps_2 open");
	if (-1 == dup2(fd_output, STDOUT_FILENO))
		error_exit("ps_2 dup2 STDOUT_FILENO");
	if (-1 == dup2(fd_pipe[0], STDIN_FILENO))
		error_exit("ps_2 dup2 STDIN_FILENO");
	close(fd_pipe[1]);
	execute(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd_pipe[2];
	pid_t	pid;
	int		re;

	if (argc != 5)
	{
		ft_putstr_fd("ex) ./pipex file1 cmd1 cmd2 file2\n", 1);
		error_exit("error arg\n");
	}
	else
	{
		if (-1 == pipe(fd_pipe))
			error_exit("error pipe");
		pid = fork();
		if (-1 == pid)
			error_exit("error fork");
		if (0 == pid)
			ps_1(fd_pipe, argv, envp);
		ps_2(fd_pipe, argv, envp);
		close(fd_pipe[0]);
		close(fd_pipe[1]);
		waitpid(-1, &re, 0);
	}
	return (0);
}
