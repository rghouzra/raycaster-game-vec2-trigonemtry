/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_doors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:11:47 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/15 11:25:08 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.h"

void	update_doors(t_data *data)
{
	t_my_list	*it;
	t_door		*door;

	it = data->doors;
	while (it)
	{
		door = it->data;
		if (abs(door->x - (data->player->pos.x / TILE_SIZE)) + 
			abs(door->y - (data->player->pos.y / TILE_SIZE)) <= 2)
			data->map[door->y][door->x] = 'd';
		else
			data->map[door->y][door->x] = 'D';
		it = it->next;
	}
}
