/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 23:36:04 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/17 10:40:08 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_data_2(t_data **data)
{
	(*data)->ceiling_color_given = false;
	(*data)->floor_color_given = false;
	(*data)->player_count = 0;
	(*data)->door_count = 0;
	(*data)->zero_count = 0;
	(*data)->one_count = 0;
	(*data)->invalid_count = 0;
	(*data)->fps_counted = 0;
	(*data)->frame_count = 30;
	(*data)->mouse_on = 0;
	(*data)->lastmouse = 0;
	(*data)->fs = NULL;
	(*data)->doors = NULL;
	gettimeofday(&((*data)->lastframetime), NULL);
	gettimeofday(&((*data)->stime), NULL);
}

void	init_data(t_data **data)
{
	*data = (t_data *)malloc(sizeof(t_data));
	if ((*data) == NULL)
		exit_failure("init_data::malloc failled");
	(*data)->frame = (t_frame *)malloc(sizeof(t_frame));
	(*data)->player = (t_player *)malloc(sizeof(t_player));
	if (((*data)->player == NULL) || ((*data)->frame == NULL))
		exit_failure("init_data::malloc failled");
	(*data)->map = NULL;
	(*data)->mini_map = NULL;
	(*data)->map_width = 0;
	(*data)->map_height = 0;
	(*data)->map_file_lines = NULL;
	(*data)->map_only_lines = NULL;
	(*data)->textures.ea_file_path = NULL;
	(*data)->textures.no_file_path = NULL;
	(*data)->textures.we_file_path = NULL;
	(*data)->textures.so_file_path = NULL;
	(*data)->textures.door_file_path = NULL;
	init_data_2(data);
}
