/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_list_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:07:34 by yrhiba            #+#    #+#             */
/*   Updated: 2023/01/09 12:09:38 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_list.h"

void	*my_list_back(t_my_list *list)
{
	t_my_list	*iterator;

	iterator = list;
	if (!iterator)
		return (NULL);
	while (iterator->next)
		iterator = iterator->next;
	return (iterator->data);
}
