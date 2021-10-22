/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejeon <yejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 13:43:41 by yejeon            #+#    #+#             */
/*   Updated: 2020/11/13 01:23:43 by yejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	len_d;
	size_t	len_s;
	size_t	len_copy;

	len_d = ft_strlen(dest);
	len_s = ft_strlen(src);
	if (len_d + 1 < size)
	{
		len_copy = size - len_d - 1;
		if (len_s < len_copy)
			len_copy = len_s;
		ft_memmove(dest + len_d, src, len_copy);
		*(dest + len_d + len_copy) = 0;
	}
	if (len_d < size)
		return (len_d + len_s);
	else
		return (size + len_s);
}
