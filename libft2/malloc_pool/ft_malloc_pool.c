/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_pool.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejeon <yejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 04:57:31 by yejeon            #+#    #+#             */
/*   Updated: 2021/05/03 22:54:12 by yejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc_pool_private.h"

void	*ft_malloc(size_t size)
{
	t_pointer	*empty;

	empty = get_empty_space();
	empty->instanse = malloc(size);
	empty->instanse_size = size;
	return (empty->instanse);
}

void	ft_free(void *p)
{
	t_pool	*pool;
	ssize_t	i;

	i = get_index_by_pointer(p);
	if (i < 0)
		return ;
	pool = get_pool();
	free(pool->array[i].instanse);
	mem_zero(&pool->array[i], sizeof(t_pointer));
}

void	ft_free_all(void)
{
	t_pool	*pool;
	size_t	i;

	pool = get_pool();
	i = 0;
	while (i < pool->max_size)
		free(pool->array[i++].instanse);
	free(pool->array);
	mem_zero(pool, sizeof(t_pool));
}

void	add_malloc(void *p, size_t size)
{
	t_pointer	*empty;

	empty = get_empty_space();
	empty->instanse = p;
	empty->instanse_size = size;
}

size_t	get_malloc_size(void *p)
{
	ssize_t	i;
	
	i = get_index_by_pointer(p);
	return ((i < 0) ? -1 : get_pool()->array[i].instanse_size);
}
