/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_update.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 02:19:26 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/17 10:45:18 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	frame_update(t_data *data)
{
	struct timeval	curtime;
	double			timepassedms;
	float			deltatime;

	gettimeofday(&curtime, NULL);
	timepassedms = (curtime.tv_sec - data->lastframetime.tv_sec) * 1000.0f
		+ (curtime.tv_usec - data->lastframetime.tv_usec) / 1000.0f;
	if (timepassedms < FRAME_MS_TIME)
		return (0);
	deltatime = timepassedms / 1000.0f;
	update_sprites(data, deltatime);
	update_player(data, deltatime);
	update_doors(data);
	cast_all_rays(data);
	update_minmap(data);
	render_floor_cilling(data);
	render_sprites(data);
	render_3d_projections(data);
	reneder_minmap(data);
	mlx_clear_window(data->mlx, data->win);
	mlx_put_image_to_window(data->mlx, data->win, data->frame->img, 0, 0);
	gettimeofday(&(data->lastframetime), NULL);
	render_footer(data);
	data->frame_count += 1;
	return (0);
}
