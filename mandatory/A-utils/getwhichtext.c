/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getwhichtext.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:52:15 by rghouzra          #+#    #+#             */
/*   Updated: 2024/01/21 15:18:16 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_frame	getwhichtext(t_data *data)
{
	if (data->dda.side == NS)
	{
		if (data->camera.ray.dir.cord.y >= 0)
			return (data->so_tex);
		else
			return (data->no_tex);
	}
	else
	{
		if (data->camera.ray.dir.cord.x > 0)
			return (data->ea_tex);
		else
			return (data->we_tex);
	}
	return (data->we_tex);
}
