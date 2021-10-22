/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejeon <yejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 22:57:28 by yejeon            #+#    #+#             */
/*   Updated: 2020/11/12 20:29:49 by yejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	len_b;
	size_t	len_l;
	size_t	i;

	if (*little == 0)
		return ((char*)big);
	len_b = ft_strlen(big);
	len_l = ft_strlen(little);
	if (len_b < len_l || len < len_l)
		return (0);
	if (len_b < len)
		i = len_b;
	else
		i = len;
	while (len_l <= i--)
	{
		if (ft_memcmp(big, little, len_l) == 0)
			return ((char*)big);
		big++;
	}
	return (0);
}
