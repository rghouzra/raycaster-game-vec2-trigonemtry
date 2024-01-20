/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:43:01 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/17 10:29:00 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	update_sprite(t_sprite *cloud, float deltatime)
{
	(void)deltatime;
	cloud->x += cloud->vx / FPS;
	if (cloud->x > WIN_WIDTH)
		cloud->x = 0;
}

void	update_sprites(t_data *data, float deltatime)
{
	int	i;
	int	x;
	int	y;

	x = 0;
	y = 0;
	i = -1;
	while (++i < SPRITE_COUNT)
	{
		update_sprite(data->cloud + i, deltatime);
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
