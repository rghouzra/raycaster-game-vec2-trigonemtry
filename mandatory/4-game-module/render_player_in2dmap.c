/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player_in2dmap.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 00:58:27 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/13 00:59:47 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.h"

void render_player_in2dmap(t_data *data)
{
	t_vector	pos;
	t_vector	vel;
	t_vector	s;
	int			player_size;

	player_size = 15;
	s.x = player_size;
	s.y = player_size;
	pos.x = data->player->pos.x - (player_size/2);
	pos.y = data->player->pos.y - (player_size/2);
	vel.x = data->player->pos.x + round(cos(data->player->rotation_angle) * 30);
	vel.y = data->player->pos.y + round(sin(data->player->rotation_angle) * 30);
	frame_render_rect(data->frame, pos, getcolor(0, 0, 255, 0), s);
	frame_render_line(data->frame, data->player->pos, vel, getcolor(0, 255, 0, 0));
}
