/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 04:33:00 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/16 11:39:21 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	update_and_allocat_map_data(t_data *data)
{
	int	i;
	int	j;

	data->map_height += 2;
	data->map_width += 2;
	if (data->map_height < MIN_MAP_HEIGHT || data->map_width < MIN_MAP_WIDTH)
		exit_failure("construct_map::the map size is too small");
	data->map = (char **)malloc(sizeof(char *) * data->map_height);
	if (!(data->map))
		exit_failure("construct_map::malloc::failed");
	i = -1;
	while (++i < data->map_height)
	{
		data->map[i] = (char *)malloc(sizeof(char) * data->map_width);
		if (!(data->map[i]))
			exit_failure("construct_map::malloc::failed");
		j = -1;
		while (++j < data->map_width)
			data->map[i][j] = ' ';
	}
}

void	construct_map(t_data *data)
{
	t_my_list	*it;
	int			i;
	int			j;
	int			len;

	update_and_allocat_map_data(data);
	it = data->map_only_lines;
	i = 1;
	while (it)
	{
		len = ft_strlen((char *)(it->data));
		j = 1;
		while (j <= len)
		{
			if (((char *)(it->data))[j - 1] != ' ')
				data->map[i][j] = ((char *)(it->data))[j - 1];
			j++;
		}
		it = it->next;
		i++;
	}
}
