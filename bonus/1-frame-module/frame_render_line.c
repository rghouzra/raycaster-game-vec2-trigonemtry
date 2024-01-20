/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_render_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 08:30:17 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/17 10:44:39 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	frame_render_line(t_frame *frame, t_vector pos1, t_vector pos2, int color)
{
	frame->dx = abs(pos1.x - pos2.x);
	frame->dy = abs(pos1.y - pos2.y);
	frame->sx = 1 - (2 * (pos1.x >= pos2.x));
	frame->sy = 1 - (2 * (pos1.y >= pos2.y));
	frame->err = frame->dx - frame->dy;
	while (pos1.x != pos2.x || pos1.y != pos2.y)
	{
		frame_pixel_put(frame, pos1.x, pos1.y, color);
		if ((frame->err * 2) >= -frame->dy)
		{
			if (pos1.x == pos2.x)
				break ;
			frame->err -= frame->dy;
			pos1.x += frame->sx;
		}
		if ((frame->err * 2) <= frame->dx)
		{
			if (pos1.y == pos2.y)
				break ;
			frame->err += frame->dx;
			pos1.y += frame->sy;
		}
	}
	return (frame_pixel_put(frame, pos1.x, pos1.y, color), 0);
}
