/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:40:30 by yrhiba            #+#    #+#             */
/*   Updated: 2023/01/10 20:52:10 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_list.h"

int	my_list_push_back(t_my_list **list, t_my_list *elem)
{
	t_my_list	*iterator;

	if (!list || !elem)
		return (-1);
	iterator = *list;
	if (!iterator)
		return (*list = elem, 0);
	while (iterator->next)
		iterator = iterator->next;
	iterator->next = elem;
	return (0);
}
