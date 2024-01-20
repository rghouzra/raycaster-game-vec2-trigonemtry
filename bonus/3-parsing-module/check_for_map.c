/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 05:11:58 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/17 11:02:12 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	set_door_adj_content(t_data *data, t_door *door)
{
	int	y;
	int	x;
	int	i;

	i = -1;
	while (++i < 4)
	{
		y = door->y + data->dr[i];
		x = door->x + data->dc[i];
		if (y < 0 || y >= data->map_height || x < 0 || x >= data->map_width)
			door->adj[i] = '1';
		else
			door->adj[i] = data->map[y][x];
	}
}

bool	check_door(t_data *data, t_door *door)
{
	set_door_adj_content(data, door);
	if (door->adj[N] == door->adj[S] && door->adj[E] == door->adj[W]
		&& (door->adj[N] == '1' || door->adj[N] == '0') && (door->adj[E] == '1'
			|| door->adj[E] == '0') && door->adj[E] != door->adj[N])
		return (true);
	return (false);
}

bool	ismapdoorvalid(t_data *data)
{
	t_my_list	*it;

	it = data->doors;
	while (it)
	{
		if (!check_door(data, (t_door *)it->data))
			return (false);
		it = it->next;
	}
	return (true);
}

void	check_for_map(t_data *data)
{
	set_and_counts_map_items(data);
	if (!ismapbordervalid(data) || !ismapdoorvalid(data)
		|| (data->player_count != 1) || (data->invalid_count != 0))
		exit_failure("check_for_map::invalid map");
}
