/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejeon <yejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 22:05:17 by yejeon            #+#    #+#             */
/*   Updated: 2021/10/29 03:12:51 by yejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	get_next_line(char **line)
{
	char	*buf;
	int		i;
	int		len;
	char	ch;

	buf = (char*)malloc(5000);
	if (0 == buf)
		error_exit("malloc");
	len = read(0, &ch, 1);
	i = 0;
	while (len && ch != '\n' && ch != 0)
	{
		if (ch != '\n' && ch != 0)
			buf[i++] = ch;
		len = read(0, &ch, 1);
	}
	buf[i] = '\n';
	buf[i + 1] = 0;
	*line = buf;
	free(buf);
	return (len);
}

void	error_exit(char *msg)
{
	if (errno && msg != NULL)
		perror(msg);
	else if (msg != NULL)
		ft_putstr_fd(msg, 2);
	else
		ft_putstr_fd("error\n", 2);
	exit(EXIT_FAILURE);
}

void	execute(char *argv, char **envp)
{
	char	**cmd;
	char	*path;	//메모리릭 확인

	cmd = ft_split(argv, ' ');
	path = find_path(cmd[0], envp);
	if (0 == path)
		error_exit("command not found");
	if (-1 == execve(path, cmd, envp))
		error_exit("command not found");
	free(path);
}

static void	ft_free(char **list)
{
	size_t	i;

	i = 0;
	while (list[i])
		free(list[i++]);
	free(list);
}

char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	char	*slash;
	int		i;

	i = 0;
	while (0 == ft_strnstr(envp[i], "PATH", 4))
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		slash = ft_strjoin(paths[i], "/");
		path = ft_strjoin(slash, cmd);
		free(slash);
		if (0 == access(path, F_OK))
		{
			ft_free(paths);
			return (path);
		}
		free(path);
		i++;
	}
	ft_free(paths);
	return (0);
}
