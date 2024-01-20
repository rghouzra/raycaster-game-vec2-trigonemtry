/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_all_rays_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:26:20 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/17 15:08:32 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	set_vertical_intecpet_2(t_data *data, int ray_id)
{
	while (is_valid_map_pos(data, data->rays[ray_id].next_vert_touch_x,
			data->rays[ray_id].next_vert_touch_y))
	{
		data->rays[ray_id].x_to_check = data->rays[ray_id].next_vert_touch_x;
		if (data->rays[ray_id].is_facing_left)
			data->rays[ray_id].x_to_check -= 1;
		data->rays[ray_id].y_to_check = data->rays[ray_id].next_vert_touch_y;
		data->rays[ray_id].hit_v_content
			= data->map[(int)(data->rays[ray_id].y_to_check
				/ TILE_HEIGTH)][(int)(data->rays[ray_id].x_to_check
				/ TILE_WIDTH)];
		if (my_string_have("1D", data->rays[ray_id].hit_v_content))
		{
			set_vertical_intecpet_3(data, ray_id);
			break ;
		}
		else
		{
			data->rays[ray_id].next_vert_touch_x += data->rays[ray_id].xstep;
			data->rays[ray_id].next_vert_touch_y += data->rays[ray_id].ystep;
		}
	}
}

void	cast_ray_2_1(t_data *data, int ray_id)
{
	data->rays[ray_id].wall_hit.x = data->rays[ray_id].vert_wall_hit_x;
	data->rays[ray_id].wall_hit.y = data->rays[ray_id].vert_wall_hit_y;
	data->rays[ray_id].distance = distance_between_2points(data->player->pos.x,
			data->player->pos.y, data->rays[ray_id].vert_wall_hit_x,
			data->rays[ray_id].vert_wall_hit_y);
}

void	cast_ray_2_2(t_data *data, int ray_id)
{
	data->rays[ray_id].distance_wallh
		= distance_between_2points(data->player->pos.x,
			data->player->pos.y, data->rays[ray_id].horz_wall_hit_x,
			data->rays[ray_id].horz_wall_hit_y);
	data->rays[ray_id].distance_wallv
		= distance_between_2points(data->player->pos.x,
			data->player->pos.y, data->rays[ray_id].vert_wall_hit_x,
			data->rays[ray_id].vert_wall_hit_y);
	if (data->rays[ray_id].distance_wallh < data->rays[ray_id].distance_wallv)
	{
		data->rays[ray_id].wall_hit.x = data->rays[ray_id].horz_wall_hit_x;
		data->rays[ray_id].wall_hit.y = data->rays[ray_id].horz_wall_hit_y;
		data->rays[ray_id].distance = data->rays[ray_id].distance_wallh;
		data->rays[ray_id].was_hit_vertical = false;
	}
	else
	{
		data->rays[ray_id].wall_hit.x = data->rays[ray_id].vert_wall_hit_x;
		data->rays[ray_id].wall_hit.y = data->rays[ray_id].vert_wall_hit_y;
		data->rays[ray_id].distance = data->rays[ray_id].distance_wallv;
		data->rays[ray_id].was_hit_horizantal = false;
	}
}

void	cast_ray_2(t_data *data, int ray_id)
{
	if (!data->rays[ray_id].was_hit_horizantal)
		cast_ray_2_1(data, ray_id);
	else if (!data->rays[ray_id].was_hit_vertical)
	{
		data->rays[ray_id].wall_hit.x = data->rays[ray_id].horz_wall_hit_x;
		data->rays[ray_id].wall_hit.y = data->rays[ray_id].horz_wall_hit_y;
		data->rays[ray_id].distance
			= distance_between_2points(data->player->pos.x,
				data->player->pos.y, data->rays[ray_id].horz_wall_hit_x,
				data->rays[ray_id].horz_wall_hit_y);
	}
	else
		cast_ray_2_2(data, ray_id);
}
