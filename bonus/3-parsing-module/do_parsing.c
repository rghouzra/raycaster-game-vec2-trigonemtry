/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 05:03:39 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/17 11:11:48 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	parse_vars_till_map_found(t_data *data, t_my_list **it)
{
	bool	map_found;

	map_found = false;
	while (*it)
	{
		check_line(data, (char *)(*it)->data, &map_found);
		if (map_found)
			return ;
		(*it) = (*it)->next;
	}
}

void	pushing_map_lines(t_data *data, t_my_list **it)
{
	while (*it)
	{
		if (my_list_push_back(&data->map_only_lines,
				my_list_new_elem(my_string_dup((char *)(*it)->data),
				my_string_free)) == -1)
			exit_failure("do_parsing::my_list_push_back::failed");
		data->map_width = ft_max(ft_strlen((char *)(*it)->data),
				data->map_width);
		data->map_height += 1;
		*it = (*it)->next;
	}
}

void	allocat_minmap(t_data *data)
{
	int	i;

	data->mini_map = (char **)malloc(sizeof(char *) * (TILE_HEIGTH
				* MINMAP_HEIGHT * MINMAP_FACTOR));
	if (!(data->mini_map))
		exit_failure("allocat_minmap::malloc::failed");
	i = -1;
	while (++i < MINMAP_HEIGHT)
	{
		data->mini_map[i] = (char *)malloc(sizeof(char) * (TILE_WIDTH
					* MINMAP_WIDTH * MINMAP_FACTOR));
		if (!(data->mini_map[i]))
			exit_failure("allocat_minmap::malloc::failed");
	}
}

void	do_parsing(t_data *data, int ac, char **av)
{
	t_my_list	*it;

	check_arguments(ac, av);
	read_input_file(data, av);
	it = data->map_file_lines;
	parse_vars_till_map_found(data, &it);
	pushing_map_lines(data, &it);
	check_for_vars(data);
	construct_map(data);
	set_directions(data);
	check_for_map(data);
	allocat_minmap(data);
	clear_parsing_data(data);
}
