/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejeon <yejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 00:01:23 by yejeon            #+#    #+#             */
/*   Updated: 2020/11/11 05:40:09 by yejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list	*head;
	t_list	*node;

	if (lst == 0 || f == 0)
		return (0);
	head = 0;
	while (lst)
	{
		node = ft_lstnew((*f)(lst->content));
		if (node == 0)
		{
			ft_lstclear(&head, del);
			return (0);
		}
		ft_lstadd_back(&head, node);
		lst = lst->next;
	}
	return (head);
}
