/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3d_projections.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 06:06:05 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/15 11:10:41 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.h"

void render_3d_projections(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < WIN_WIDTH)
	{
		data->rays[i].correct_wall_dis = data->rays[i].distance
			* cos( data->rays[i].ray_angle - data->player->rotation_angle);

		if (data->rays[i].correct_wall_dis < 10)
			data->rays[i].correct_wall_dis = 10;

		data->rays[i].wall_height = (TILE_HEIGTH / data->rays[i].correct_wall_dis)
								* ((WIN_WIDTH / 2) / tan(FOV / 2));

		data->rays[i].start_row = round((WIN_HEIGHT / 2) - (data->rays[i].wall_height / 2));
		if (data->rays[i].start_row < 0)
			data->rays[i].start_row = 0;

		data->rays[i].end_row = round((WIN_HEIGHT / 2) + (data->rays[i].wall_height / 2));
		if (data->rays[i].start_row >= WIN_HEIGHT)
			data->rays[i].start_row = (WIN_HEIGHT - 1);

		if (data->rays[i].hit_content == 'D')
		{
			data->rays[i].tex = &(data->door_tex);
		}
		else if (data->rays[i].was_hit_horizantal)
		{
			if (data->rays[i].is_facing_down)
				data->rays[i].tex = &(data->so_tex);
			else
				data->rays[i].tex = &(data->no_tex);
		}
		else
		{
			if (data->rays[i].is_facing_left)
				data->rays[i].tex = &(data->we_tex);
			else
				data->rays[i].tex = &(data->ea_tex);
		}

		if (data->rays[i].was_hit_vertical)
			data->rays[i].texture_x = data->rays[i].wall_hit.y % TILE_SIZE;
		else
			data->rays[i].texture_x = data->rays[i].wall_hit.x % TILE_SIZE;

		data->rays[i].texture_x = (data->rays[i].texture_x * data->rays[i].tex->width) / (TILE_SIZE * 1.0f);

		j = data->rays[i].start_row - 1;
		while (++j < data->rays[i].end_row)
		{
			data->rays[i].texture_y = j + (data->rays[i].wall_height / 2) - (WIN_HEIGHT / 2);
			data->rays[i].texture_y = data->rays[i].texture_y * (data->rays[i].tex->height / (data->rays[i].wall_height * 1.0f));
			frame_pixel_put(data->frame, i, j, frame_get_color(data->rays[i].tex, data->rays[i].texture_x, data->rays[i].texture_y));
		}
	}
}
