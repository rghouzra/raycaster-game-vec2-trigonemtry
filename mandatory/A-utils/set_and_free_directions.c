/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_and_free_directions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 05:44:19 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/15 10:13:09 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	set_directions(t_data *data)
{
	data->dc = (int *)malloc(sizeof(int) * 4);
	data->dr = (int *)malloc(sizeof(int) * 4);
	data->dr[0] = 1;
	data->dr[1] = -1;
	data->dr[2] = 0;
	data->dr[3] = 0;
	data->dc[0] = 0;
	data->dc[1] = 0;
	data->dc[2] = 1;
	data->dc[3] = -1;
}

void	free_directions(t_data *data)
{
	free(data->dr);
	free(data->dc);
	data->dr = NULL;
	data->dc = NULL;
}
