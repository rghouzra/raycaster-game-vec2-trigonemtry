/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:46:38 by yrhiba            #+#    #+#             */
/*   Updated: 2023/01/10 20:47:15 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_list.h"

int	my_list_push_front(t_my_list **list, t_my_list *elem)
{
	t_my_list	*iterator;

	if (!elem || !list)
		return (-1);
	iterator = *list;
	if (!iterator)
		return (*list = elem, 0);
	elem->next = iterator;
	*list = elem;
	return (0);
}
