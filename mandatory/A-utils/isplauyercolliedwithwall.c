/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isplauyercolliedwithwall.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 10:26:42 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/15 11:18:46 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

bool	isplauyercolliedwithwall(t_data *data, t_vector player_pos)
{
	int	x;
	int	y;

	if (player_pos.x < 0 || player_pos.y < 0 || player_pos.x >= (TILE_WIDTH
			* data->map_width) || player_pos.y >= (TILE_HEIGTH
			* data->map_height))
		return (true);
	x = player_pos.x / TILE_WIDTH;
	y = player_pos.y / TILE_HEIGTH;
	return (data->map[y][x] == '1');
}
