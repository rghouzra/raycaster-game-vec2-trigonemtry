/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 23:36:04 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/18 17:10:43 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	clear_maps(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->map_height)
		free(data->map[i]);
	free(data->map);
	i = -1;
	while (++i < MINMAP_HEIGHT)
		free(data->mini_map[i]);
	free(data->mini_map);
}

void	clear_data(t_data **data)
{
	clear_maps(*data);
	my_list_clear(&((*data)->doors), clear_door);
	mlx_clear_window((*data)->mlx, (*data)->win);
	mlx_destroy_image((*data)->mlx, (*data)->frame->img);
	mlx_destroy_window((*data)->mlx, (*data)->win);
	free((*data)->frame);
	free((*data)->player);
	free((*data)->textures.ea_file_path);
	free((*data)->textures.no_file_path);
	free((*data)->textures.we_file_path);
	free((*data)->textures.so_file_path);
}
