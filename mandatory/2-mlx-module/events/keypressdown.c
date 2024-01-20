/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypressdown.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:47:01 by rghouzra          #+#    #+#             */
/*   Updated: 2024/01/18 06:40:28 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	movebackandfront(int keycode, t_data *data)
{
	double	x;
	double	y;

	if (keycode == W_KEY)
	{
		x = data->camera.pos.cord.x + scalevec(data->camera.dir, SCALE).cord.x;
		y = data->camera.pos.cord.y + scalevec(data->camera.dir, SCALE).cord.y;
	}
	else if (keycode == S_KEY)
	{
		x = data->camera.pos.cord.x - scalevec(data->camera.dir, SCALE).cord.x;
		y = data->camera.pos.cord.y - scalevec(data->camera.dir, SCALE).cord.y;
	}
	else
		return ;
	if (!(0 <= x && x < data->map_width - 2 && 0 <= y && y < data->map_height
			- 2))
		return ;
	if (data->map[(int)y][(int)x] != '0')
		return ;
	data->camera.pos.cord.x = x;
	data->camera.pos.cord.y = y;
}

void	moveleftright(int keycode, t_data *data)
{
	double	x;
	double	y;

	if (keycode == D_KEY)
	{
		x = data->camera.pos.cord.x + scalevec(data->camera.plane,
				SCALE).cord.x;
		y = data->camera.pos.cord.y + scalevec(data->camera.plane,
				SCALE).cord.y;
	}
	else if (keycode == A_KEY)
	{
		x = data->camera.pos.cord.x - scalevec(data->camera.plane,
				SCALE).cord.x;
		y = data->camera.pos.cord.y - scalevec(data->camera.plane,
				SCALE).cord.y;
	}
	else
		return ;
	if (!(0 <= x && x < data->map_width - 2 && 0 <= y && y < data->map_height
			- 2) || data->map[(int)y][(int)x] != '0')
		return ;
	data->camera.pos.cord.x = x;
	data->camera.pos.cord.y = y;
}

int	keypressdown(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
		redcrosspressed(data);
	if (keycode == RIGHT_KEY)
	{
		data->camera.dir = rotate_vec(data->camera.dir, degree_to_rad(10.1));
		data->camera.plane = rotate_vec(data->camera.plane,
				degree_to_rad(10.1));
	}
	if (keycode == LEFT_KEY)
	{
		data->camera.dir = rotate_vec(data->camera.dir, degree_to_rad(-10.1));
		data->camera.plane = rotate_vec(data->camera.plane,
				degree_to_rad(-10.1));
	}
	movebackandfront(keycode, data);
	moveleftright(keycode, data);
	return (0);
}
