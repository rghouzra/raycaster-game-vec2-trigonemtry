/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_2dmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 06:20:25 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/13 01:05:49 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.h"

void render_2dmap(t_data *data)
{
	int color;
	t_vector pos;
	t_vector g;
	t_vector s;

	s.x = TILE_WIDTH;
	s.y = TILE_HEIGTH;
	pos.y = -1;
	while (++(pos.y) < data->map_height)
	{
		pos.x = -1;
		while (++(pos.x) < data->map_width)
		{
			if (data->map[pos.y][pos.x] == 'X')
				color = getcolor(0, 156, 156, 156);
			if (data->map[pos.y][pos.x] == '0')
				color = getcolor(0, 255, 255, 255);
			if (data->map[pos.y][pos.x] == '1')
				color = getcolor(0, 0, 0, 0);
			g.x = pos.x * TILE_WIDTH;
			g.y = pos.y * TILE_HEIGTH;
			frame_render_rect(data->frame, g, color, s);
		}
	}
}
