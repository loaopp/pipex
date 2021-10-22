/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejeon <yejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:41:21 by yejeon            #+#    #+#             */
/*   Updated: 2021/10/22 16:17:51 by yejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

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

	cmd = ft_split(argv, ' ');
	if (-1 == execve(find_path(cmd[0], envp), cmd, envp))
		error_exit("command not found");
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
