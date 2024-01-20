/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypressdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 09:54:12 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/14 10:19:13 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	keypressdup(int keycode, t_data *data)
{
	if (keycode == RIGHT_KEY)
		data->player->look_direction = 0;
	if (keycode == LEFT_KEY)
		data->player->look_direction = 0;
	if (keycode == W_KEY)
		data->player->walk_direction = 0;
	if (keycode == S_KEY)
		data->player->walk_direction = 0;
	if (keycode == D_KEY)
		data->player->turn_direction = 0;
	if (keycode == A_KEY)
		data->player->turn_direction = 0;
	return (0);
}
