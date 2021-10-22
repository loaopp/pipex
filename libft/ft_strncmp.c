/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejeon <yejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 13:41:53 by yejeon            #+#    #+#             */
/*   Updated: 2020/11/11 00:36:55 by yejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char *ch1;
	unsigned char *ch2;

	ch1 = (unsigned char*)s1;
	ch2 = (unsigned char*)s2;
	while (n--)
	{
		if (*ch1 != *ch2 || !*ch1 || !*ch2)
			return (*ch1 - *ch2);
		ch1++;
		ch2++;
	}
	return (0);
}
