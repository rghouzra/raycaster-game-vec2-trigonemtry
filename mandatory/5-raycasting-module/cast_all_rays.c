/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_all_rays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:39:31 by rghouzra          #+#    #+#             */
/*   Updated: 2024/01/18 06:58:41 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_dda(t_data *data)
{
	if (data->camera.ray.dir.cord.x == 0)
		data->dda.deltadist.x = 1e30;
	else
		data->dda.deltadist.x = fabs(1 / data->camera.ray.dir.cord.x);
	if (data->camera.ray.dir.cord.y == 0)
		data->dda.deltadist.y = 1e30;
	else
		data->dda.deltadist.y = fabs(1 / data->camera.ray.dir.cord.y);
	data->dda.sidedist.x = data->dda.deltadist.x * (data->camera.pos.cord.x \
	- data->dda.mapx);
	data->dda.sidedist.y = data->dda.deltadist.y * (data->camera.pos.cord.y \
	- data->dda.mapy);
	data->dda.stepx = (-1 * (data->camera.ray.dir.cord.x < 0)) + \
	(1 * (data->camera.ray.dir.cord.x >= 0));
	data->dda.stepy = (-1 * (data->camera.ray.dir.cord.y < 0)) + \
	(1 * (data->camera.ray.dir.cord.y >= 0));
	if (data->camera.ray.dir.cord.x >= 0)
		data->dda.sidedist.x = data->dda.deltadist.x * (data->dda.mapx + 1 \
		- data->camera.pos.cord.x);
	if (data->camera.ray.dir.cord.y >= 0)
		data->dda.sidedist.y = data->dda.deltadist.y * (data->dda.mapy + 1 \
		- data->camera.pos.cord.y);
}

/*
PH : PD = HB : DC
-> Euclidean : raydir = yDist : raydirY
-> Euclidean * raydirY = raydir * yDist
-> Euclidean / raydir = yDist / raydirY

PH : PD = AH : DE 
-> Euclidean : raydir = PerpWallDist : dir
-> Euclidean * dir = raydir * PerpWallDist
-> Euclidean / raydir = PerpWallDist / dir
-> yDist / raydirY = PerpWallDist / dir
-> yDist / raydirY = PerpWallDist
-> (mapY - posY + (1 - stepY) / 2) / raydirY = PerpWallDist
*/

void	rayintersect(t_data *data)
{
	init_dda(data);
	while (!data->dda.hit && ++data->dda.count < 1e3)
	{
		if (data->dda.sidedist.x > data->dda.sidedist.y)
		{
			data->dda.sidedist.y += data->dda.deltadist.y;
			data->dda.mapy += data->dda.stepy;
			data->dda.side = NS;
		}
		else
		{
			data->dda.sidedist.x += data->dda.deltadist.x;
			data->dda.mapx += data->dda.stepx;
			data->dda.side = EW;
		}
		data->dda.hit = (data->map[data->dda.mapy][data->dda.mapx] != '0');
	}
	data->camera.ray.dir.cord.x += ((data->camera.ray.dir.cord.x == 0) * 0.01);
	data->camera.ray.dir.cord.y += ((data->camera.ray.dir.cord.y == 0) * 0.01);
	data->dda.perpwalldist = (((data->dda.mapx - data->camera.pos.cord.x + \
	(1 - data->dda.stepx) / 2) / data->camera.ray.dir.cord.x) * \
	(data->dda.side == EW)) \
	+ (((data->dda.mapy - data->camera.pos.cord.y \
	+ (1 - data->dda.stepy) / 2) / \
	data->camera.ray.dir.cord.y) * (data->dda.side == NS));
}

void	draw_text(t_data *data, int x, t_frame	tex, int y)
{
	y = data->wall.start;
	tex = getwhichtext(data);
	if (data->dda.side == EW)
		data->wall.wallx = data->camera.pos.cord.y + \
	((data)->dda.perpwalldist * data->camera.ray.dir.cord.y);
	else
		data->wall.wallx = data->camera.pos.cord.x + \
	((data)->dda.perpwalldist * data->camera.ray.dir.cord.x);
	data->wall.wallx -= floor(data->wall.wallx);
	data->wall.texx = (int)(data->wall.wallx * (double)tex.width);
	data->wall.step = ((double)tex.height / data->wall.lineh);
	data->wall.texpos = (data->wall.start - (WIN_HEIGHT / 2) \
	+ (data->wall.lineh / 2)) * data->wall.step;
	while (y < data->wall.end)
	{
		data->wall.texy = (int)data->wall.texpos;
		data->wall.texpos += data->wall.step;
		frame_pixel_put(data->frame, x, y, frame_get_color(&tex, \
			data->wall.texx, data->wall.texy));
		y++;
	}
}

void	draw_wall(t_data *data, int x)
{
	int		y;
	double	height_half;
	double	line_half;

	y = 0;
	if (data->dda.perpwalldist == 0)
		data->dda.perpwalldist = 1;
	data->wall.lineh = ((int)(WIN_HEIGHT / data->dda.perpwalldist));
	height_half = (WIN_HEIGHT / 2.0);
	line_half = data->wall.lineh / 2.0;
	data->wall.start = (int)(height_half) - (int)(line_half);
	if (data->wall.start < 0)
		data->wall.start = 0;
	data->wall.end = (int)(height_half) + (int)(line_half);
	if (data->wall.end >= WIN_HEIGHT)
		data->wall.end = WIN_HEIGHT - 1;
	while (y < data->wall.start)
		frame_pixel_put(data->frame, x, y++, getcolor(0, \
			data->ceiling_color.red, data->ceiling_color.green, \
				data->ceiling_color.blue));
	y = data->wall.end;
	while (y < WIN_HEIGHT)
		frame_pixel_put(data->frame, x, y++, getcolor(0, data->floor_color.red, \
			data->floor_color.green, data->floor_color.blue));
	draw_text(data, x, getwhichtext(data), 0);
}

void	cast_all_rays(t_data *data)
{
	int			x;
	t_camera	*cam;

	x = 0;
	cam = &data->camera;
	while (x < WIN_WIDTH)
	{
		cam->ray.origin = cam->pos;
		cam->planx = (double)2 * x / (double)WIN_WIDTH - (double)1;
		cam->ray.dir.cord.x = cam->dir.cord.x \
			+ (cam->plane.cord.x * cam->planx);
		cam->ray.dir.cord.y = cam->dir.cord.y \
			+ (cam->plane.cord.y * cam->planx);
		data->dda.mapx = (int)data->camera.pos.cord.x;
		data->dda.mapy = (int)data->camera.pos.cord.y;
		data->dda.hit = 0;
		data->dda.count = 0;
		rayintersect(data);
		draw_wall(data, x);
		x++;
	}
}
