/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_pool_private2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejeon <yejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 04:54:18 by yejeon            #+#    #+#             */
/*   Updated: 2021/05/01 20:54:45 by yejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc_pool_private.h"

ssize_t	get_index_by_pointer(void *p)
{
	t_pool	*pool;
	ssize_t	i;

	pool = get_pool();
	i = 0;
	while (i < pool->max_size)
	{
		if (pool->array[i].instanse == p)
			return (i);
		i++;
	}
	return (-1);
}

t_pointer	*get_empty_space(void)
{
	ssize_t	i;

	i = get_index_by_pointer(NULL);
	if (i < 0)
		i = size_up_pool();
	return (&get_pool()->array[i]);
}

