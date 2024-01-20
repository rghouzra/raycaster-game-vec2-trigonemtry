/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_all_rays_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:08:16 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/17 15:09:14 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	set_horiz_intecpet_3(t_data *data, int ray_id)
{
	data->rays[ray_id].horz_wall_hit_x
		= data->rays[ray_id].next_horz_touch_x;
	data->rays[ray_id].horz_wall_hit_y
		= data->rays[ray_id].next_horz_touch_y;
	data->rays[ray_id].was_hit_horizantal = true;
}

void	set_horiz_intecpet_2(t_data *data, int ray_id)
{
	while (is_valid_map_pos(data, data->rays[ray_id].next_horz_touch_x,
			data->rays[ray_id].next_horz_touch_y))
	{
		data->rays[ray_id].x_to_check = data->rays[ray_id].next_horz_touch_x;
		data->rays[ray_id].y_to_check = data->rays[ray_id].next_horz_touch_y;
		if (data->rays[ray_id].is_facing_up)
			data->rays[ray_id].y_to_check -= 1;
		data->rays[ray_id].hit_h_content
			= data->map[(int)(data->rays[ray_id].y_to_check
				/ TILE_HEIGTH)][(int)(data->rays[ray_id].x_to_check
				/ TILE_WIDTH)];
		if (my_string_have("1D", data->rays[ray_id].hit_h_content))
		{
			set_horiz_intecpet_3(data, ray_id);
			break ;
		}
		else
		{
			data->rays[ray_id].next_horz_touch_x += data->rays[ray_id].xstep;
			data->rays[ray_id].next_horz_touch_y += data->rays[ray_id].ystep;
		}
	}
}

void	set_vertical_intecpet_3(t_data *data, int ray_id)
{
	data->rays[ray_id].vert_wall_hit_x
		= data->rays[ray_id].next_vert_touch_x;
	data->rays[ray_id].vert_wall_hit_y
		= data->rays[ray_id].next_vert_touch_y;
	data->rays[ray_id].was_hit_vertical = true;
}
