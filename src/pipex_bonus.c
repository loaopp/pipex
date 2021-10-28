/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejeon <yejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 22:05:14 by yejeon            #+#    #+#             */
/*   Updated: 2021/10/29 04:00:39 by yejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	usage(void)
{
	ft_putstr_fd("ex) ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2\n", 1);
	ft_putstr_fd("ex) ./pipex here_doc LIMITER cmd cmd1 file\n", 1);
	exit(EXIT_SUCCESS);
}

void	ps_child(char *cmd, char **envp)
{
	int		fd_pipe[2];
	pid_t	pid;

	if (-1 == pipe(fd_pipe))
		error_exit("ps_child pipe");
	pid = fork();
	if (-1 == pid)
		error_exit("ps_child fork");
	if (0 == pid)
	{
		if (-1 == dup2(fd_pipe[1], STDOUT_FILENO))
			error_exit("ps_child dup2 STDOUT_FILENO");
		close(fd_pipe[0]);
		execute(cmd, envp);
	}
	else
	{
		if (-1 == dup2(fd_pipe[0], STDIN_FILENO))
			error_exit("ps_child dup2 STDIN_FILENO");
		close(fd_pipe[1]);
		waitpid(pid, 0, 0);
	}
}

void	here_doc(char *limiter, int argc)
{
	int		fd_pipe[2];
	pid_t	pid;
	char	*line;

	if (argc < 6)
		usage();
	if (-1 == pipe(fd_pipe))
		error_exit("here_doc pipe");
	pid = fork();
	if (0 == pid)
	{
		close(fd_pipe[0]);
		while (get_next_line(&line))
		{
			if (0 == ft_strncmp(line, limiter, ft_strlen(limiter)))
				exit(EXIT_SUCCESS);
			write(fd_pipe[1], line, ft_strlen(line));
		}
	}
	else
	{
		dup2(fd_pipe[0], STDIN_FILENO);
		close(fd_pipe[1]);
		wait(0);
	}
}

int	get_fd(char *filename, int type)
{
	int	fd;

	fd = -1;
	if (type == O_APPEND)
		fd = open(filename, O_WRONLY | O_CREAT | type, 0777);
	else if (type == O_TRUNC)
		fd = open(filename, O_WRONLY | O_CREAT | type, 0777);
	else if (type == O_RDONLY)
		fd = open(filename, type, 0777);
	if (-1 == fd)
		error_exit("get_fd");
	return (fd);
}

int	main(int argc, char **argv, char **envp)
{
	int	fd_in_out[2];
	int	i;

	if (5 <= argc)
	{
		if (0 == ft_strncmp(argv[1], "here_doc", 8))
		{
			i = 3;
			fd_in_out[1] = get_fd(argv[argc - 1], O_APPEND);
			here_doc(argv[2], argc);
		}
		else
		{
			i = 2;
			fd_in_out[0] = get_fd(argv[1], O_RDONLY);
			fd_in_out[1] = get_fd(argv[argc - 1], O_TRUNC);
			dup2(fd_in_out[0], STDIN_FILENO);
		}
		while (i < argc - 2)
			ps_child(argv[i++], envp);
		dup2(fd_in_out[1], STDOUT_FILENO);
		execute(argv[argc - 2], envp);
	}
	usage();
	return (0);
}
