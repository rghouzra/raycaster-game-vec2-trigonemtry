/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:50:24 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/15 17:10:55 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	render_sprites(t_data *data)
{
	int	i;
	int	x;
	int	y;

	i = -1;
	x = 0;
	y = 0;
	while (++i < SPRITE_COUNT)
	{
		frame_render_sprite(data, data->cloud[i].x, data->cloud[i].y);
		x++;
		if (x * SPRITE_SEP > WIN_WIDTH)
		{
			if (!y)
			{
				x = 0;
				y += 1;
			}
			else
				break ;
		}
	}
}
