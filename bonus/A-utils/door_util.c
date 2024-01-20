/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 09:45:10 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/17 11:16:23 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	clear_door(void **door)
{
	free(*((t_door **)door));
}

void	add_door(t_data *data, int i, int j)
{
	t_door	*door;

	door = (t_door *)malloc(sizeof(t_door));
	if (!door)
		exit_failure("add_door::malloc::failed");
	door->y = i;
	door->x = j;
	if (my_list_push_back(&(data->doors), my_list_new_elem(door, clear_door))
		== -1)
		exit_failure("add_door::my_list_push_back::failed");
}
