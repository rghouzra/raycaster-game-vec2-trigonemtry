/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:24:41 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/18 11:25:31 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	check_no_var(t_data *data, char **parts)
{
	if (my_string_compare(parts[0], "NO") != LS_EQUAL)
		return ;
	if (my_string_update(&(data->textures.no_file_path), parts[1]) == -1)
		exit_failure("check_no_var::my_string_update::failed");
}

void	check_so_var(t_data *data, char **parts)
{
	if (my_string_compare(parts[0], "SO") != LS_EQUAL)
		return ;
	if (my_string_update(&(data->textures.so_file_path), parts[1]) == -1)
		exit_failure("check_so_var::my_string_update::failed");
}

void	check_we_var(t_data *data, char **parts)
{
	if (my_string_compare(parts[0], "WE") != LS_EQUAL)
		return ;
	if (my_string_update(&(data->textures.we_file_path), parts[1]) == -1)
		exit_failure("check_we_var::my_string_update::failed");
}
