/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_pool_private1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejeon <yejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 04:54:18 by yejeon            #+#    #+#             */
/*   Updated: 2021/05/03 22:56:48 by yejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc_pool_private.h"

void	mem_zero(void *p, size_t i)
{
	while (i--)
		((char*)p)[i] = 0;
}

t_pointer	*make_pool(size_t cnt)
{
	t_pointer	*arr_pointer;

	arr_pointer = (t_pointer*)malloc(cnt * sizeof(t_pointer));
	mem_zero(arr_pointer, cnt * sizeof(t_pointer));
	return (arr_pointer);
}

t_pool	*get_pool(void)
{
	static t_pool	pool;

	if (NULL == pool.array)
	{
		pool.max_size = DEFAULT_POOL_SIZE;
		pool.array = make_pool(pool.max_size);
	}
	return (&pool);
}

void	copy_pool(t_pointer *from, t_pointer *to, size_t i)
{
	while (i--)
	{
		to[i].instanse = from[i].instanse;
		to[i].instanse_size = from[i].instanse_size;
	}
}

size_t	size_up_pool(void)
{
	t_pool	*pool;
	t_pool	temp;

	pool = get_pool();
	temp = *pool;
	pool->max_size *= 2;
	pool->array = make_pool(pool->max_size);
	if (temp.array)
		copy_pool(temp.array, pool->array, temp.max_size);
	return (temp.max_size);
}
