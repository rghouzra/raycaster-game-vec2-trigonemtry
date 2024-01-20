/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:06:57 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/17 11:07:18 by yrhiba           ###   ########.fr       */
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
		&& my_string_compare(parts[0], "DOOR") != LS_EQUAL
		&& my_string_len(parts[0]) > 0);
}

void	check_no_var(t_data *data, char **parts)
{
	if (my_string_compare(parts[0], "NO") != LS_EQUAL)
		return ;
	if (data->textures.no_file_path)
		exit_failure("check_no_var::double key");
	if (my_string_update(&(data->textures.no_file_path), parts[1]) == -1)
		exit_failure("check_no_var::my_string_update::failed");
}

void	check_so_var(t_data *data, char **parts)
{
	if (my_string_compare(parts[0], "SO") != LS_EQUAL)
		return ;
	if (data->textures.so_file_path)
		exit_failure("check_no_var::double key");
	if (my_string_update(&(data->textures.so_file_path), parts[1]) == -1)
		exit_failure("check_so_var::my_string_update::failed");
}

void	check_we_var(t_data *data, char **parts)
{
	if (my_string_compare(parts[0], "WE") != LS_EQUAL)
		return ;
	if (data->textures.we_file_path)
		exit_failure("check_no_var::double key");
	if (my_string_update(&(data->textures.we_file_path), parts[1]) == -1)
		exit_failure("check_we_var::my_string_update::failed");
}

void	check_ea_var(t_data *data, char **parts)
{
	if (my_string_compare(parts[0], "EA") != LS_EQUAL)
		return ;
	if (data->textures.ea_file_path)
		exit_failure("check_no_var::double key");
	if (my_string_update(&(data->textures.ea_file_path), parts[1]) == -1)
		exit_failure("check_ea_var::my_string_update::failed");
}
