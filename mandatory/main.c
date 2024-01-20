/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 23:08:33 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/18 17:12:49 by rghouzra         ###   ########.fr       */
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
	mlx_hook(data->win, ON_KEYDOWN, 0, keypressdown, data);
	mlx_hook(data->win, ON_DESTROY, 0, redcrosspressed, data);
	mlx_loop_hook(data->mlx, frame_update, data);
	return (mlx_loop(data->mlx), clear_data(&data), 0);
}
