/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_pool.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejeon <yejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 04:54:38 by yejeon            #+#    #+#             */
/*   Updated: 2021/05/10 01:03:30 by yejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_POOL_H
# define FT_MALLOC_POOL_H

# include <unistd.h>

// ft_free를 하면 실제론 해제하지말고 남겨놨다가
// ft_malloc이 왔을때 사이즈를 확인해서 기존에 만들었던걸 넘기도록 업글하

void	*ft_malloc(size_t size);
void	ft_free(void *p);
void	ft_free_all();
/*
 * add to managment pointer
 * *p : pointer already made of malloc.
 * size : the size of where *p is pointing.
*/
void	add_malloc(void *p, size_t size);
/*
 * *p : pointer you want known size
*/
size_t	get_malloc_size(void *p);

#endif
