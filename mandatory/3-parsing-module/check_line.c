/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 02:36:41 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/18 11:24:32 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

bool	check_map_start(char **parts)
{
	return (my_string_compare(parts[0], "NO") != LS_EQUAL
		&& my_string_compare(parts[0], "SO") != LS_EQUAL
		&& my_string_compare(parts[0], "WE") != LS_EQUAL
		&& my_string_compare(parts[0], "EA") != LS_EQUAL
		&& my_string_compare(parts[0], "F") != LS_EQUAL
		&& my_string_compare(parts[0], "C") != LS_EQUAL
		&& my_string_len(parts[0]) > 0);
}

void	check_ea_var(t_data *data, char **parts)
{
	if (my_string_compare(parts[0], "EA") != LS_EQUAL)
		return ;
	if (my_string_update(&(data->textures.ea_file_path), parts[1]) == -1)
		exit_failure("check_ea_var::my_string_update::failed");
}

void	check_f_var(t_data *data, char **parts)
{
	char	**colors;

	if (my_string_compare(parts[0], "F") != LS_EQUAL)
		return ;
	data->floor_color_given = true;
	colors = my_string_split(parts[1], " ,");
	if (my_strings_count(colors) != 3)
		exit_failure("check_f_var::invalid floor color given");
	data->floor_color.red = ft_atoi(colors[0]);
	data->floor_color.green = ft_atoi(colors[1]);
	data->floor_color.blue = ft_atoi(colors[2]);
	my_strings_free(&colors);
	if (!is_valid_color(&(data->floor_color)))
		exit_failure("check_f_var::invalid floor color given");
}

void	check_c_var(t_data *data, char **parts)
{
	char	**colors;

	if (my_string_compare(parts[0], "C") != LS_EQUAL)
		return ;
	data->ceiling_color_given = true;
	colors = my_string_split(parts[1], " ,");
	if (my_strings_count(colors) != 3)
		exit_failure("check_c_var::invalid ceiling color given");
	data->ceiling_color.red = ft_atoi(colors[0]);
	data->ceiling_color.green = ft_atoi(colors[1]);
	data->ceiling_color.blue = ft_atoi(colors[2]);
	my_strings_free(&colors);
	if (!is_valid_color(&(data->ceiling_color)))
		exit_failure("check_c_var::invalid ceiling color given");
}

void	check_line(t_data *data, char *line, bool *map_found)
{
	char	**parts;

	parts = my_string_split_by_first(line, " ");
	if (!parts)
		exit_failure("check_line::my_string_split_by_first::failed");
	if (!ft_strlen(parts[0]))
	{
		my_strings_free(&parts);
		return ;
	}
	if (check_map_start(parts))
	{
		*map_found = true;
		my_strings_free(&parts);
		return ;
	}
	check_no_var(data, parts);
	check_so_var(data, parts);
	check_we_var(data, parts);
	check_ea_var(data, parts);
	check_f_var(data, parts);
	check_c_var(data, parts);
	my_strings_free(&parts);
}
