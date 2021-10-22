/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejeon <yejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 04:12:12 by yejeon            #+#    #+#             */
/*   Updated: 2021/03/20 04:24:05 by yejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthex_fd_bonus(size_t n, int upper, int fd)
{
	if (n >> 4)
		ft_puthex_fd_bonus(n >> 4, upper, fd);
	if (upper)
		write(fd, &"0123456789ABCDEF"[n & 0x0f], 1);
	else
		write(fd, &"0123456789abcdef"[n & 0x0f], 1);
}
