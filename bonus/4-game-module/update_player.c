/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 10:00:44 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/16 09:28:34 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	update_player(t_data *data, float deltatime)
{
	float		move_step;
	t_vector	new_player_pos;
	double		angle;

	data->player->rotation_angle += data->player->turn_direction
		* data->player->turn_speed * deltatime;
	if (!data->player->walk_direction && !data->player->look_direction)
		return ;
	angle = data->player->rotation_angle + atan2(data->player->look_direction,
			data->player->walk_direction);
	move_step = data->player->walk_speed * deltatime;
	new_player_pos.x = data->player->pos.x + round(cos(angle) * move_step);
	new_player_pos.y = data->player->pos.y + round(sin(angle) * move_step);
	if (isplauyercolliedwithwall(data, new_player_pos))
		return ;
	data->player->pos.x = new_player_pos.x;
	data->player->pos.y = new_player_pos.y;
}
