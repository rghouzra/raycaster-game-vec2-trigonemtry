/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_render_sprite.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:02:09 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/15 17:12:25 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	frame_render_sprite(t_data *data, int x, int y)
{
	t_vector	p;
	int			color;
	double		dis;

	p.y = -1;
	while (++p.y < data->sprite.height)
	{
		p.x = -1;
		while (++p.x < data->sprite.width)
		{
			dis = (p.y - y) * (p.y - y) + (p.x - x) * (p.x - x);
			color = frame_get_color(&(data->sprite), p.x, p.y);
			if (color < 2434341)
				color = getcolor(50, data->ceiling_color.red,
						data->ceiling_color.green, data->ceiling_color.blue);
			frame_pixel_put(data->frame, x + p.x, y + p.y, color);
		}
	}
}
