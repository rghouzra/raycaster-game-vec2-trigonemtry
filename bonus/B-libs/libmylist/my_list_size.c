/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:12:42 by yrhiba            #+#    #+#             */
/*   Updated: 2023/01/09 18:58:57 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_list.h"

long long	my_list_size(t_my_list *list)
{
	t_my_list	*iterator;
	long long	size;

	iterator = list;
	size = 0;
	if (my_list_empty(list))
		return (size);
	while (iterator)
	{
		iterator = iterator->next;
		size++;
	}
	return (size);
}
