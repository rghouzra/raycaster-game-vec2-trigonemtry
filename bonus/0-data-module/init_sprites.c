/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:33:58 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/15 17:11:42 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_sprites(t_data *data)
{
	int	i;
	int	x;
	int	y;

	i = -1;
	x = 0;
	y = 0;
	while (++i < SPRITE_COUNT)
	{
		data->cloud[i].x = x;
		data->cloud[i].y = y;
		data->cloud[i].vx = 50;
		data->cloud[i].vy = 0;
		x += SPRITE_SEP;
		if (x > WIN_WIDTH)
		{
			if (!y)
			{
				x = 50;
				y += 80;
			}
			else
				break ;
		}
	}
}
