/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map_pos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 02:26:48 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/13 04:08:18 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

bool	is_valid_map_pos(t_data *data, float x, float y)
{
	return (0 <= x && x < (TILE_WIDTH * data->map_width) && 0 <= y
		&& y < (TILE_HEIGTH * data->map_height));
}
