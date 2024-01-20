/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_list_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:54:44 by yrhiba            #+#    #+#             */
/*   Updated: 2023/01/10 21:32:08 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_list.h"

void	*my_list_get(t_my_list *list, long long index)
{
	t_my_list	*iterator;
	long long	i;

	if (index < 0 || my_list_empty(list))
		return (NULL);
	i = 0;
	iterator = list;
	while (iterator->next)
	{
		if (i == index)
			break ;
		iterator = iterator->next;
		i++;
	}
	if (i == index)
		return (iterator->data);
	return (NULL);
}
