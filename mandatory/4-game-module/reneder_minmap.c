/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reneder_minmap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 00:07:07 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/15 11:47:26 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.h"

void render_minmap_fov(t_data *data)
{
	for (int i = 0; i < WIN_WIDTH; i++)
	{
		int x = data->player->minmap_pos.x + cos(data->rays[i].ray_angle) * 50 * MINMAP_FACTOR;
		int y = data->player->minmap_pos.y + sin(data->rays[i].ray_angle) * 50 * MINMAP_FACTOR;
		data->rays[i].wall_hit.x = x;
		data->rays[i].wall_hit.y = y;
		frame_render_line(data->frame, data->player->minmap_pos, data->rays[i].wall_hit, getcolor(100, 220, 0, 30));
	}
}

void render_minmap_player(t_data *data)
{
	t_vector	pos;
	t_vector	vel;
	t_vector	s;
	int			player_size;

	data->player->minmap_pos.x += (TILE_WIDTH * MINMAP_FACTOR);
	data->player->minmap_pos.y += (TILE_HEIGTH * MINMAP_FACTOR);
	player_size = 14 * MINMAP_FACTOR;
	s.x = player_size;
	s.y = player_size;
	pos.x = data->player->minmap_pos.x - (player_size/2);
	pos.y = data->player->minmap_pos.y - (player_size/2);
	vel.x = data->player->minmap_pos.x + round(cos(data->player->rotation_angle - (FOV * 0.5 * data->player->look_direction)) * (70 * MINMAP_FACTOR));
	vel.y = data->player->minmap_pos.y + round(sin(data->player->rotation_angle - (FOV * 0.5 * data->player->look_direction)) * (70 * MINMAP_FACTOR));
	frame_render_rect(data->frame, pos, getcolor(0, 0, 220, 30), s);
	frame_render_line(data->frame, data->player->minmap_pos, vel, getcolor(0, 0, 0, 255));
	render_minmap_fov(data);
}

void	reneder_minmap(t_data *data)
{
	int color;
	t_vector pos;
	t_vector g;
	t_vector s;

	s.x = TILE_WIDTH * MINMAP_FACTOR;
	s.y = TILE_HEIGTH * MINMAP_FACTOR;
	pos.y = -2;
	while (++(pos.y) < MINMAP_HEIGHT + 1)
	{
		pos.x = -2;
		while (++(pos.x) < MINMAP_WIDTH + 1)
		{
			if (pos.x == -1 || pos.y == -1 || pos.x == MINMAP_WIDTH || pos.y == MINMAP_HEIGHT)
				color = getcolor(0, 25, 0, 230);
			else if (data->mini_map[pos.y][pos.x] == 'X')
				color = getcolor(0, 156, 156, 156);
			else if (data->mini_map[pos.y][pos.x] == '0')
				color = getcolor(0, 255, 255, 255);
			else if (data->mini_map[pos.y][pos.x] == '1')
				color = getcolor(0, 0, 0, 0);
			else if (data->mini_map[pos.y][pos.x] == 'D')
				color = getcolor(0, 150, 150, 150);
			else if (data->mini_map[pos.y][pos.x] == 'd')
				color = getcolor(0, 0, 150, 150);
			g.x = round((pos.x + 1) * TILE_WIDTH * MINMAP_FACTOR);
			g.y = round((pos.y + 1) * TILE_HEIGTH * MINMAP_FACTOR);
			frame_render_rect(data->frame, g, color, s);
		}
	}
	render_minmap_player(data);
}
