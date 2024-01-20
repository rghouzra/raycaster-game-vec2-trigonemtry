/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 10:00:44 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/15 11:25:50 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	update_player(t_data *data, float deltatime)
{
	float		move_step;
	t_vector	new_player_pos;

	data->player->rotation_angle += data->player->turn_direction
		* data->player->turn_speed * deltatime;
	move_step = data->player->walk_speed * deltatime
		* data->player->walk_direction;
	new_player_pos.x = data->player->pos.x
		+ round(cos(data->player->rotation_angle) * move_step);
	new_player_pos.y = data->player->pos.y
		+ round(sin(data->player->rotation_angle) * move_step);
	if (isplauyercolliedwithwall(data, new_player_pos))
		return ;
	data->player->pos.x = new_player_pos.x;
	data->player->pos.y = new_player_pos.y;
	data->player->rotation_angle += (FOV * 0.5 * data->player->look_direction);
}
