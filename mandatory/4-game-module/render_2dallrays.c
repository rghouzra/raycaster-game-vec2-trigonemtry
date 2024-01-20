/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_2dallrays.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 04:08:43 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/13 04:39:40 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.h"

void	render_2dallrays(t_data *data)
{
	for (int i = 0; i < WIN_WIDTH; i++)
	{
		int x = data->player->pos.x + cos(data->rays[i].ray_angle) * data->rays[i].distance;
		int y = data->player->pos.y + sin(data->rays[i].ray_angle) * data->rays[i].distance;
		data->rays[i].wall_hit.x = x;
		data->rays[i].wall_hit.y = y;
		frame_render_line(data->frame, data->player->pos, data->rays[i].wall_hit, getcolor(0, 220, 0, 30));
	}
}
