/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 23:08:33 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/17 10:24:12 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int ac, char **av)
{
	t_data	*data;

	init_data(&data);
	do_parsing(data, ac, av);
	init_mlx(data);
	load_textures(data);
	init_sprites(data);
	mlx_hook(data->win, ON_KEYDOWN, 0, keypressdown, data);
	mlx_hook(data->win, ON_KEYUP, 0, keypressdup, data);
	mlx_hook(data->win, ON_MOUSEDOWN, 0, mousedown, data);
	mlx_hook(data->win, ON_MOUSEUP, 0, mouseup, data);
	mlx_hook(data->win, ON_MOUSEMOVE, 0, mousemove, data);
	mlx_hook(data->win, ON_DESTROY, 0, redcrosspressed, data);
	mlx_loop_hook(data->mlx, frame_update, data);
	return (mlx_loop(data->mlx), clear_data(&data), 0);
}
