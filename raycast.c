#include "raycastfs.h"


void debug_draw_ray(t_raycast *ptr, t_ray ray){
	static int i;
	i++;
	if(i < 30)
		return;
	i= 0;
	draw_line(ptr, ray.origin.cord, op_two_vectors(ray.origin, scaleVec(ray.dir, WIDTH + HEIGHT), ADD).cord, 0xff);
}

void init(t_vec2 **p){
	p[0]->cord = (t_cord){WIDTH / 2, HEIGHT / 2};
	p[1]->cord = (t_cord){-1, 0};
	p[2]->cord = (t_cord){0, 0.66};
}


void debug_draw_player(t_raycast *ptr){
	fillrecborders(ptr, (t_cord){ptr->camera.pos.cord.x - 5, ptr->camera.pos.cord.y - 5}, \
		(t_cord){ptr->camera.pos.cord.x + 5,ptr->camera.pos.cord.y + 5}, 0xFF0000);
}

void debug_draw_map(t_raycast *p){
	int i, j;
	i = 0;
	while(i < MAP_H){
		j = 0;
		while(j < MAP_W){
			// map[i][j] == 1
				fillrec(p, (t_cord){
					.x = j * GSIZE,
					.y = i * GSIZE
					},
					(t_cord){
					.x = (j * GSIZE) + GSIZE,
					.y =   (i * GSIZE) + GSIZE
					} , ((0xFFFFFF) * (map[i][j] == 1)));
			// else
			// 	fillrec(p, (t_cord){
			// 		.x = j*( WIDTH)/ MAP_W,
			// 		.y = i*(HEIGHT)/ MAP_H
			// 		},
			// 		(t_cord){
			// 		.x = (j*( WIDTH)/ MAP_W +(( WIDTH)/MAP_W)) ,
			// 		.y =   i*(HEIGHT)/ MAP_H + ((HEIGHT) / MAP_H)
			// 		} , 0x0);
			j++;
		}
		i++;
	}
}

void draw_ray(t_raycast *ptr){
	(void)ptr;
}

void ultimate_dda(t_raycast *ptr){
	ptr->dda.hit = 0;
	ptr->dda.camera = ptr->camera;
	ptr->dda.mapx = (int)ptr->dda.camera.pos.cord.x;
	ptr->dda.mapy = (int)ptr->dda.camera.pos.cord.y;
	ptr->dda.deltadist.x = 1 / ((ptr->dda.camera.dir.cord.x == 0) * 1e30 + ptr->dda.camera.dir.cord.x);
	ptr->dda.deltadist.y = 1 / ((ptr->dda.camera.dir.cord.y == 0) * 1e30 + ptr->dda.camera.dir.cord.y);
	ptr->dda.sidedist.x = ptr->dda.deltadist.x * (ptr->dda.camera.pos.cord.x - ptr->dda.mapx);
	ptr->dda.stepx = -1;
	ptr->dda.sidedist.y = ptr->dda.deltadist.y * (ptr->dda.camera.pos.cord.y - ptr->dda.mapy);
	ptr->dda.stepy = -1;
	if(ptr->dda.camera.ray.dir.cord.x >= 0){
		ptr->dda.stepx = 1;
		ptr->dda.sidedist.x = ptr->dda.deltadist.x * (ptr->dda.mapx + 1 - ptr->dda.camera.pos.cord.x);
	}	
	if(ptr->dda.camera.ray.dir.cord.y >= 0){
		ptr->dda.sidedist.y = ptr->dda.deltadist.y * (ptr->dda.mapy + 1 - ptr->dda.camera.pos.cord.y);
		ptr->dda.stepy = 1;
	}
	while(!ptr->dda.hit){
		if(ptr->dda.sidedist.x > ptr->dda.sidedist.y){
			ptr->dda.sidedist.y += ptr->dda.deltadist.y;
			ptr->dda.mapy += ptr->dda.stepy;
			ptr->dda.side = NS;
		}
		else{
			ptr->dda.sidedist.x += ptr->dda.deltadist.x;
			ptr->dda.mapx += ptr->dda.stepx;
			ptr->dda.side = EW;
		}
		ptr->dda.hit = (map[ptr->dda.mapy][ptr->dda.mapx] != 0);
	}
	ptr->dda.perpwalldist = ((ptr->dda.sidedist.x - ptr->dda.deltadist.x) * (ptr->dda.side == EW)) + \
	((ptr->dda.sidedist.y - ptr->dda.deltadist.y) * (ptr->dda.side == NS));
}

void draw_wall(t_raycast *ptr, int x){
	int  y = 0;
	for(y= 0; y < HEIGHT;y++)
	{
		if(y < HEIGHT / 2 - ptr->dda.perpwalldist || y > HEIGHT / 2 + ptr->dda.perpwalldist)
			my_mlx_pixel_put(&ptr->img, x, y, 0xff04f);
		else
			my_mlx_pixel_put(&ptr->img, x, y, 0xfffffa);
	}
}

void	raycast(t_raycast *ptr){
	int x = 0;
	t_camera *cam;

	cam = &ptr->camera;
	cam->ray.origin = cam->pos;
	// debug_draw_grid(ptr);
	// debug_draw_map(ptr);
	debug_draw_player(ptr);
	while(x < WIDTH){
		ptr->camera.planx = (double)2 * x/ (double)WIDTH - (double)1;
		cam->ray.dir.cord.x = cam->dir.cord.x + cam->plane.cord.x * ptr->camera.planx;
		cam->ray.dir.cord.y = cam->dir.cord.y + cam->plane.cord.y * ptr->camera.planx;
		ultimate_dda(ptr);
		draw_wall(ptr, x);
		// debug_draw_ray(ptr,cam->ray);
		x++;
	}
	mlx_put_image_to_window(ptr->ptr, ptr->ptr_win,ptr->img.img,0, 0);
}
