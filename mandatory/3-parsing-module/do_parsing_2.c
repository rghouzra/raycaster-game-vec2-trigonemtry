/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_parsing_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:20:47 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/18 11:20:53 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	check_arguments(int ac, char **av)
{
	if (ac != 2 || !check_ext(av[1], ".cub"))
	{
		exit_failure("one file must be provided with <.cub> extension");
	}
}

void	read_input_file(t_data *data, char **av)
{
	if (!read_file_content(data, av[1]))
	{
		exit_failure("read_file_content()::failed");
	}
}

void	check_for_vars(t_data *data)
{
	if (!data->floor_color_given || !data->ceiling_color_given
		|| !(data->textures.ea_file_path) || !(data->textures.so_file_path)
		|| !(data->textures.we_file_path) || !(data->textures.no_file_path))
		exit_failure("check_for_vars::vars missing in the file");
}
