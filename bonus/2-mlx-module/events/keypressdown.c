/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypressdown.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 00:42:26 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/16 08:38:15 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	keypressdown(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
		redcrosspressed(data);
	if (keycode == RIGHT_KEY)
		data->player->turn_direction = +1;
	if (keycode == LEFT_KEY)
		data->player->turn_direction = -1;
	if (keycode == W_KEY)
		data->player->walk_direction = +1;
	if (keycode == S_KEY)
		data->player->walk_direction = -1;
	if (keycode == D_KEY)
		data->player->look_direction = +1;
	if (keycode == A_KEY)
		data->player->look_direction = -1;
	return (0);
}
