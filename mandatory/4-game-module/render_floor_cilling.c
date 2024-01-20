/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_floor_cilling.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 02:33:11 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/14 02:49:01 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.h"

void	render_floor_cilling(t_data *data)
{
	t_vector p, e;

	p.x = 0;
	p.y = 0;
	e.x = WIN_WIDTH;
	e.y = WIN_HEIGHT / 2;
	frame_render_rect(data->frame,
		p, 
		getcolor(
			50,
			data->ceiling_color.red,
			data->ceiling_color.green,
			data->ceiling_color.blue
		), 
		e
	);
	p.x = 0;
	p.y = e.y;
	e.x = WIN_WIDTH;
	e.y = WIN_HEIGHT;
	frame_render_rect(data->frame,
		p, 
		getcolor(
			120,
			data->floor_color.red,
			data->floor_color.green,
			data->floor_color.blue
		),
		e
	);
}
