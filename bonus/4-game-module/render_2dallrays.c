/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_2dallrays.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 04:08:43 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/17 11:34:29 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	render_2dallrays(t_data *data)
{
	int	x;
	int	y;
	int	i;

	i = -1;
	while (++i < WIN_WIDTH)
	{
		x = data->player->pos.x + cos(data->rays[i].ray_angle)
			* data->rays[i].distance;
		y = data->player->pos.y + sin(data->rays[i].ray_angle)
			* data->rays[i].distance;
		data->rays[i].wall_hit.x = x;
		data->rays[i].wall_hit.y = y;
		frame_render_line(data->frame, data->player->pos,
			data->rays[i].wall_hit, getcolor(0, 220, 0, 30));
	}
}
