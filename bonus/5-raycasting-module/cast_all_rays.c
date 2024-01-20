/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_all_rays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 01:04:29 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/17 15:00:15 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	setup_ray(t_data *data, int ray_id)
{
	data->rays[ray_id].ray_angle
		= normalize_angle(data->rays[ray_id].ray_angle);
	data->rays[ray_id].is_facing_down = (0 < data->rays[ray_id].ray_angle
			&& data->rays[ray_id].ray_angle < M_PI);
	data->rays[ray_id].is_facing_up = !(data->rays[ray_id].is_facing_down);
	data->rays[ray_id].is_facing_left = ((M_PI
				/ 2) < data->rays[ray_id].ray_angle
			&& data->rays[ray_id].ray_angle < (3 * M_PI / 2));
	data->rays[ray_id].is_facing_right = !(data->rays[ray_id].is_facing_left);
	data->rays[ray_id].was_hit_horizantal = false;
	data->rays[ray_id].was_hit_vertical = false;
}

void	set_horiz_intecpet(t_data *data, int ray_id)
{
	data->rays[ray_id].yintercept = floor(data->player->pos.y / TILE_HEIGTH)
		* TILE_HEIGTH;
	if (data->rays[ray_id].is_facing_down)
		data->rays[ray_id].yintercept += TILE_HEIGTH;
	data->rays[ray_id].xintercept = data->player->pos.x
		+ (data->rays[ray_id].yintercept - data->player->pos.y)
		/ tan(data->rays[ray_id].ray_angle);
	data->rays[ray_id].ystep = TILE_HEIGTH;
	if (data->rays[ray_id].is_facing_up)
		data->rays[ray_id].ystep *= -1;
	data->rays[ray_id].xstep = TILE_HEIGTH / tan(data->rays[ray_id].ray_angle);
	if ((data->rays[ray_id].is_facing_left && data->rays[ray_id].xstep > 0)
		|| (data->rays[ray_id].is_facing_right && data->rays[ray_id].xstep < 0))
		data->rays[ray_id].xstep *= -1;
	data->rays[ray_id].next_horz_touch_x = data->rays[ray_id].xintercept;
	data->rays[ray_id].next_horz_touch_y = data->rays[ray_id].yintercept;
	set_horiz_intecpet_2(data, ray_id);
}

void	set_vertical_intecpet(t_data *data, int ray_id)
{
	data->rays[ray_id].xintercept = floor(data->player->pos.x / TILE_WIDTH)
		* TILE_WIDTH;
	if (data->rays[ray_id].is_facing_right)
		data->rays[ray_id].xintercept += TILE_WIDTH;
	data->rays[ray_id].yintercept = data->player->pos.y
		+ (data->rays[ray_id].xintercept - data->player->pos.x)
		* tan(data->rays[ray_id].ray_angle);
	data->rays[ray_id].xstep = TILE_WIDTH;
	if (data->rays[ray_id].is_facing_left)
		data->rays[ray_id].xstep *= -1;
	data->rays[ray_id].ystep = TILE_HEIGTH * tan(data->rays[ray_id].ray_angle);
	if ((data->rays[ray_id].is_facing_up && data->rays[ray_id].ystep > 0)
		|| (data->rays[ray_id].is_facing_down && data->rays[ray_id].ystep < 0))
		data->rays[ray_id].ystep *= -1;
	data->rays[ray_id].next_vert_touch_x = data->rays[ray_id].xintercept;
	data->rays[ray_id].next_vert_touch_y = data->rays[ray_id].yintercept;
	set_vertical_intecpet_2(data, ray_id);
}

void	cast_ray(t_data *data, int ray_id)
{
	set_horiz_intecpet(data, ray_id);
	set_vertical_intecpet(data, ray_id);
	cast_ray_2(data, ray_id);
	if (data->rays[ray_id].was_hit_horizantal)
		data->rays[ray_id].hit_content = data->rays[ray_id].hit_h_content;
	else
		data->rays[ray_id].hit_content = data->rays[ray_id].hit_v_content;
}

void	cast_all_rays(t_data *data)
{
	int	ray_id;

	ray_id = 0;
	data->rays[ray_id].ray_angle = data->player->rotation_angle - (FOV / 2);
	while (true)
	{
		setup_ray(data, ray_id);
		cast_ray(data, ray_id);
		if (++ray_id >= WIN_WIDTH)
			break ;
		data->rays[ray_id].ray_angle = data->rays[ray_id - 1].ray_angle + (FOV
				/ WIN_WIDTH);
	}
}
