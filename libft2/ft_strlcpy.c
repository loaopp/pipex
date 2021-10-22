/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejeon <yejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 13:48:32 by yejeon            #+#    #+#             */
/*   Updated: 2020/11/11 22:47:26 by yejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	if (!dest || !src)
		return (0);
	if (size)
		if (0 == ft_memccpy(dest, src, 0, size))
			dest[size - 1] = 0;
	return (ft_strlen(src));
}
