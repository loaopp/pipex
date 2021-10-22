/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejeon <yejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 22:28:12 by yejeon            #+#    #+#             */
/*   Updated: 2020/11/13 02:07:20 by yejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_count(const char *s, char c)
{
	size_t			flag;
	size_t			cnt;
	unsigned char	ch;

	flag = 1;
	cnt = 0;
	ch = (unsigned char)c;
	while (*s)
	{
		if (flag && *s != ch)
		{
			cnt++;
			flag = 0;
		}
		else if (!flag && *s == ch)
			flag = 1;
		s++;
	}
	return (cnt);
}

static char	*ft_get_word(char **pos, unsigned char c)
{
	char	*start;

	start = 0;
	while (**pos)
	{
		if (!start && **pos != c)
			start = *pos;
		else if (start && **pos == c)
			break ;
		(*pos)++;
	}
	if (start)
		return (ft_substr(start, 0, *pos - start));
	return (0);
}

static void	ft_free(void **list)
{
	size_t	i;

	i = 0;
	while (list[i])
		free(list[i++]);
	free(list);
}

char		**ft_split(char const *s, char c)
{
	char	**list;
	char	*p;
	size_t	cnt;
	size_t	i;

	if (0 == s)
		return (0);
	cnt = ft_get_count(s, c);
	list = (char**)ft_calloc(cnt + 1, sizeof(char*));
	if (0 == list)
		return (0);
	i = 0;
	p = (char*)s;
	while (i < cnt)
	{
		list[i] = ft_get_word(&p, c);
		if (0 == list[i])
		{
			ft_free((void**)list);
			return (0);
		}
		i++;
	}
	return (list);
}
