/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 00:35:26 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/14 03:28:31 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT + FOOTER_HEIGHT,
			WIN_TITLE);
	data->frame->img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT
			+ FOOTER_HEIGHT);
	data->frame->addr = mlx_get_data_addr(data->frame->img,
			&data->frame->bits_per_pixel, &data->frame->line_length,
			&data->frame->endian);
}
