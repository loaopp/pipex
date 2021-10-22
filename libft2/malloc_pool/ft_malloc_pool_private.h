/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_pool_private.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejeon <yejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 18:34:14 by yejeon            #+#    #+#             */
/*   Updated: 2021/05/01 18:36:53 by yejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_POOL_PRIVATE_H
# define FT_MALLOC_POOL_PRIVATE_H

# include <unistd.h>
# include <stdlib.h>

# define DEFAULT_POOL_SIZE 10

typedef struct	s_pointer
{
	void		*instanse;
	size_t		instanse_size;
}				t_pointer;

typedef struct	s_pool
{
	t_pointer	*array;
	size_t		max_size;
}				t_pool;

void			copy_pool(t_pointer *from, t_pointer *to, size_t i);
void			mem_zero(void *p, size_t i);
t_pool			*get_pool(void);
t_pointer		*get_empty_space(void);
t_pointer		*make_pool(size_t cnt);
ssize_t			get_index_by_pointer(void *p);
size_t			size_up_pool(void);

#endif
