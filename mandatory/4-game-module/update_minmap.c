/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_minmap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 23:33:40 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/14 00:04:15 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.h"

void	update_minmap(t_data *data)
{
	t_vector p;
	t_vector i;
	t_vector r;

	p.x = floor(data->player->pos.x / (TILE_WIDTH * 1.0f));
	p.y = floor(data->player->pos.y / (TILE_HEIGTH * 1.0f));
	r.x = data->player->pos.x - p.x * TILE_WIDTH;
	r.y = data->player->pos.y - p.y * TILE_HEIGTH;
	i.y = p.y - (MINMAP_HEIGHT / 2) - 1;
	while (++i.y < p.y + (MINMAP_HEIGHT / 2))
	{
		i.x = p.x - (MINMAP_WIDTH / 2) - 1;
		while (++i.x < p.x + (MINMAP_WIDTH / 2))
			if (0 <= i.y && i.y < data->map_height && 0 <= i.x && i.x < data->map_width)
				data->mini_map[i.y - (p.y - MINMAP_HEIGHT / 2)][i.x - (p.x - MINMAP_WIDTH / 2)] = data->map[i.y][i.x];
			else
				data->mini_map[i.y - (p.y - MINMAP_HEIGHT / 2)][i.x - (p.x - MINMAP_WIDTH / 2)] = 'X';
	}
	data->player->minmap_pos.y = MINMAP_HEIGHT * TILE_HEIGTH * MINMAP_FACTOR / 2;
	data->player->minmap_pos.x = MINMAP_WIDTH * TILE_WIDTH * MINMAP_FACTOR / 2;
	data->player->minmap_pos.y += r.y * MINMAP_FACTOR;
	data->player->minmap_pos.x += r.x * MINMAP_FACTOR;
}
