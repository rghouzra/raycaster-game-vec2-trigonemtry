/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:25:00 by yrhiba            #+#    #+#             */
/*   Updated: 2023/05/30 23:51:18 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_list.h"

int	my_list_clear(t_my_list **list, void (*data_clear)(void **))
{
	t_my_list	*iterator;
	t_my_list	*next;

	if (!list)
		return (-1);
	iterator = *list;
	while (iterator)
	{
		next = iterator->next;
		data_clear(&(iterator->data));
		free(iterator);
		iterator = next;
	}
	return (*list = (t_my_list *)0, 0);
}
