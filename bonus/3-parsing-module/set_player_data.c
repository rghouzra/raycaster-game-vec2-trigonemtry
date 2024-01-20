/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 08:13:29 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/15 13:01:25 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	set_player_data(t_data *data, int y, int x)
{
	data->player->pos.x = (x * TILE_WIDTH) + (TILE_WIDTH / 2);
	data->player->pos.y = (y * TILE_HEIGTH) + (TILE_HEIGTH / 2);
	data->player->turn_direction = 0;
	data->player->walk_direction = 0;
	data->player->look_direction = 0;
	data->player->turn_speed = 150 * (M_PI / 180);
	data->player->walk_speed = 250;
	if (data->map[y][x] == 'N')
		data->player->rotation_angle = -90 * (M_PI / 180);
	if (data->map[y][x] == 'S')
		data->player->rotation_angle = 90 * (M_PI / 180);
	if (data->map[y][x] == 'E')
		data->player->rotation_angle = 0 * (M_PI / 180);
	if (data->map[y][x] == 'W')
		data->player->rotation_angle = 180 * (M_PI / 180);
}
