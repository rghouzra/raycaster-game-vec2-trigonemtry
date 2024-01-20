/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_list_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:12:40 by yrhiba            #+#    #+#             */
/*   Updated: 2023/01/10 20:51:38 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_list.h"

int	my_list_insert(t_my_list **list, t_my_list *elem, long long index)
{
	t_my_list	*iterator;
	t_my_list	*prev;
	long long	i;

	if (!elem || !list)
		return (-1);
	if (index < 0)
		return (-2);
	if (index == 0)
		return (my_list_push_front(list, elem));
	if (my_list_empty(*list))
		return (-2);
	i = 0;
	iterator = *list;
	while (iterator)
	{
		if (i == index)
			break ;
		prev = iterator;
		iterator = iterator->next;
		i++;
	}
	if (i != index)
		return (-2);
	return (prev->next = elem, elem->next = iterator, 0);
}
