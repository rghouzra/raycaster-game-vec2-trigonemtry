/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_footer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 03:23:42 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/15 12:59:39 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.h"

void	render_footer(t_data *data)
{
	data->fs = my_string_dup("fps ( ");

	char *n = ft_itoa(data->fps_counted);
	my_string_append(&data->fs, n);
	my_string_append(&data->fs, " )");

	mlx_string_put(data->mlx, data->win, WIN_WIDTH - 180, WIN_HEIGHT - 50, getcolor(0, 0, 0, 0), data->fs);

	double pt = (data->lastframetime.tv_sec - data->stime.tv_sec) * 1000.0f
		+ (data->lastframetime.tv_usec - data->stime.tv_usec) / 1000.0f;

	if (pt >= 1e3)
	{
		data->fps_counted = data->frame_count;
		data->frame_count = 0;
		ft_memcpy(&(data->stime), &(data->lastframetime), sizeof(struct timeval));
	}

	free(n);
	free(data->fs);
}
