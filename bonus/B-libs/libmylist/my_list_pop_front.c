/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_list_pop_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:02:34 by yrhiba            #+#    #+#             */
/*   Updated: 2023/05/30 23:58:01 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_list.h"

int	my_list_pop_front(t_my_list **list, void (*data_clear)(void **))
{
	t_my_list	*iterator;

	if (!list)
		return (-1);
	if (my_list_empty(*list))
		return (0);
	iterator = *list;
	*list = iterator->next;
	return (data_clear(&(iterator->data)), free(iterator), 0);
}
