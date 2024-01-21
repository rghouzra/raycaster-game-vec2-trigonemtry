/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 08:13:29 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/21 15:16:08 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	set_player_data(t_data *data, int y, int x)
{
	data->player->pos.x = x;
	data->player->pos.y = y;
	if (data->map[y][x] == 'N')
		data->camera.dir.cord = (t_cord){0, -1};
	if (data->map[y][x] == 'S')
		data->camera.dir.cord = (t_cord){0, 1};
	if (data->map[y][x] == 'E')
		data->camera.dir.cord = (t_cord){1, 0};
	if (data->map[y][x] == 'W')
		data->camera.dir.cord = (t_cord){-1, 0};
}
