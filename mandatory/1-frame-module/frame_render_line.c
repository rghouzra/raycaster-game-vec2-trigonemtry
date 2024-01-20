/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_render_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 08:30:17 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/15 20:41:43 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.h"
int s = 0;

int	frame_render_line(t_frame *frame, t_vector pos1, t_vector pos2, int color)
{
	s += 1;
	printf("%d\n", s);
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int err;

	dx = abs(pos1.x - pos2.x);
	dy = abs(pos1.y - pos2.y);
	sx = 1 - (2 * (pos1.x >= pos2.x));
	sy = 1 - (2 * (pos1.y >= pos2.y));
	err = dx - dy;
	while (pos1.x != pos2.x || pos1.y != pos2.y)
	{
		frame_pixel_put(frame, pos1.x, pos1.y, color);
		if ((err * 2) >= -dy)
		{
			if (pos1.x == pos2.x)
				break;
			err -= dy;
			pos1.x += sx;
		}
		if ((err * 2) <= dx)
		{
			if (pos1.y == pos2.y)
				break;
			err += dx;
			pos1.y += sy;
		}
		puts("-");
	}
	frame_pixel_put(frame, pos1.x, pos1.y, color);
	return (0);
}
