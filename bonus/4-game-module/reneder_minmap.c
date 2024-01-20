/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reneder_minmap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 00:07:07 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/17 11:44:24 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	render_minmap_fov(t_data *data)
{
	int	x;
	int	y;
	int	i;

	i = -1;
	while (++i < WIN_WIDTH)
	{
		x = data->player->minmap_pos.x + cos(data->rays[i].ray_angle) * 50
			* MINMAP_FACTOR;
		y = data->player->minmap_pos.y + sin(data->rays[i].ray_angle) * 50
			* MINMAP_FACTOR;
		data->rays[i].wall_hit.x = x;
		data->rays[i].wall_hit.y = y;
		frame_render_line(data->frame, data->player->minmap_pos,
			data->rays[i].wall_hit, getcolor(100, 220, 0, 30));
	}
}

void	render_minmap_player(t_data *data)
{
	t_vector	pos;
	t_vector	s;
	int			player_size;

	data->player->minmap_pos.x += (TILE_WIDTH * MINMAP_FACTOR);
	data->player->minmap_pos.y += (TILE_HEIGTH * MINMAP_FACTOR);
	player_size = 14 * MINMAP_FACTOR;
	s.x = player_size;
	s.y = player_size;
	pos.x = data->player->minmap_pos.x - (player_size / 2);
	pos.y = data->player->minmap_pos.y - (player_size / 2);
	frame_render_rect(data->frame, pos, getcolor(0, 0, 220, 30), s);
	render_minmap_fov(data);
}

void	reneder_minmap_2(t_data *data, t_minmap minmap)
{
	while (++(minmap.pos.x) < MINMAP_WIDTH + 1)
	{
		if (minmap.pos.x == -1 || minmap.pos.y == -1
			|| minmap.pos.x == MINMAP_WIDTH || minmap.pos.y == MINMAP_HEIGHT)
			minmap.color = getcolor(0, 25, 0, 230);
		else if (data->mini_map[minmap.pos.y][minmap.pos.x] == ' ')
			minmap.color = getcolor(0, 156, 156, 156);
		else if (data->mini_map[minmap.pos.y][minmap.pos.x] == '0')
			minmap.color = getcolor(0, 255, 255, 255);
		else if (data->mini_map[minmap.pos.y][minmap.pos.x] == '1')
			minmap.color = getcolor(0, 0, 0, 0);
		else if (data->mini_map[minmap.pos.y][minmap.pos.x] == 'D')
			minmap.color = getcolor(0, 150, 150, 150);
		else if (data->mini_map[minmap.pos.y][minmap.pos.x] == 'd')
			minmap.color = getcolor(0, 0, 150, 150);
		minmap.g.x = round((minmap.pos.x + 1) * TILE_WIDTH * MINMAP_FACTOR);
		minmap.g.y = round((minmap.pos.y + 1) * TILE_HEIGTH * MINMAP_FACTOR);
		frame_render_rect(data->frame, minmap.g, minmap.color, minmap.s);
	}
}

void	reneder_minmap(t_data *data)
{
	t_minmap	minmap;

	minmap.s.x = TILE_WIDTH * MINMAP_FACTOR;
	minmap.s.y = TILE_HEIGTH * MINMAP_FACTOR;
	minmap.pos.y = -2;
	while (++(minmap.pos.y) < MINMAP_HEIGHT + 1)
	{
		minmap.pos.x = -2;
		reneder_minmap_2(data, minmap);
	}
	render_minmap_player(data);
}
