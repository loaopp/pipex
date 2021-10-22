/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejeon <yejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 08:59:35 by yejeon            #+#    #+#             */
/*   Updated: 2021/03/20 04:42:12 by yejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_hex_bonus(size_t n, char *buf_17)
{
	const char	*base = "0123456789abcdef";
	size_t		i;

	if (n >> 4)
		i = ft_hex_bonus(n >> 4, buf_17);
	else
		i = 0;
	buf_17[i] = base[n & 0x0f];
	buf_17[i + 1] = 0;
	return (i + 1);
}
