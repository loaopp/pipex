/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejeon <yejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:31:45 by yejeon            #+#    #+#             */
/*   Updated: 2020/11/21 04:47:33 by yejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*p;

	if (0 == s1 && 0 == s2)
		return (0);
	else if (0 == s1 && s2)
		return (ft_strdup(s2));
	else if (s1 && 0 == s2)
		return (ft_strdup(s1));
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	p = ft_calloc(len_s1 + len_s2 + 1, sizeof(char));
	if (!p)
		return (0);
	ft_memcpy(p, s1, len_s1);
	ft_memcpy(p + len_s1, s2, len_s2);
	return (p);
}
