/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejeon <yejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 08:11:49 by yejeon            #+#    #+#             */
/*   Updated: 2020/11/08 08:12:10 by yejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev_bonus(char *s)
{
	char	*p1;
	char	*p2;
	char	ch;

	p1 = s;
	p2 = s + ft_strlen(s) - 1;
	while (p1 < p2)
	{
		ch = *p1;
		*p1 = *p2;
		*p2 = ch;
		p1++;
		p2--;
	}
	return (s);
}
