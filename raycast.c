#include "raycastfs.h"


void debug_draw_rays(t_raycast *ptr, t_ray ray){
	draw_line(ptr, (t_cord){ray.origin.cord.x*GSIZE ,ray.origin.cord.y * GSIZE},\
	 op_two_vectors((t_vec2){(t_cord){ray.origin.cord.x*GSIZE ,ray.origin.cord.y * GSIZE}},\
	  scaleVec(ray.dir,GSIZE), ADD).cord, 0xff);
}

void init(t_vec2 **p){
	p[0]->cord = (t_cord){WIDTH / 2, HEIGHT / 2};
	p[1]->cord = (t_cord){-1, 0};
	p[2]->cord = (t_cord){0, 0.66};
}


void debug_draw_player(t_raycast *ptr){
	fillrecborders(ptr, (t_cord){ptr->camera.pos.cord.x , ptr->camera.pos.cord.y }, \
		(t_cord){ptr->camera.pos.cord.x + 5,ptr->camera.pos.cord.y + 5}, 0xFF0000);
}

void debug_draw_map(t_raycast *p){
	int i, j;
	i = 0;
	while(i < MAP_H){
		j = 0;
		while(j < MAP_W){
				if(j == (int)p->camera.pos.cord.x && i == (int)p->camera.pos.cord.y)
					fillrec(p, (t_cord){
						j*GSIZE, i*GSIZE
					},
					(t_cord){
						(j*GSIZE) + 50,
						(i*GSIZE)+50
					},
						0xffff20
					);
				else
					fillrec(p, (t_cord){
						.x = j * GSIZE,
						.y = i * GSIZE
					},
					(t_cord){
						.x = (j * GSIZE) + GSIZE,
						.y =   (i * GSIZE) + GSIZE
					} , ((0xFFFFFF) * (map[i][j] == 1)));
			j++;
		}
		i++;
	}
}

void draw_ray(t_raycast *ptr){
	(void)ptr;
}

void init_dda(t_raycast *ptr){
	ptr->dda.hit = 0;
	ptr->dda.camera = ptr->camera;
	ptr->dda.mapx = (int)ptr->dda.camera.pos.cord.x;
	ptr->dda.mapy = (int)ptr->dda.camera.pos.cord.y;
	ptr->dda.deltadist.x = 1 / ((ptr->dda.camera.dir.cord.x == 0) * 1e30 + ptr->dda.camera.dir.cord.x);
	ptr->dda.deltadist.y = 1 / ((ptr->dda.camera.dir.cord.y == 0) * 1e30 + ptr->dda.camera.dir.cord.y);
	ptr->dda.sidedist.x = ptr->dda.deltadist.x * (ptr->dda.camera.pos.cord.x - ptr->dda.mapx);
	ptr->dda.sidedist.y = ptr->dda.deltadist.y * (ptr->dda.camera.pos.cord.y - ptr->dda.mapy);
	ptr->dda.stepx = -1;
	ptr->dda.stepy = -1;
}

void ultimate_dda(t_raycast *ptr){
	init_dda(ptr);
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
		if(ptr->dda.mapx >= MAP_W || ptr->dda.mapy >= MAP_H){
			fprintf(stderr, "out of range of map array\n");
			break;
		}
		ptr->dda.hit = (map[ptr->dda.mapy][ptr->dda.mapx] != 0);
	}
	ptr->dda.perpwalldist = ((ptr->dda.sidedist.x - ptr->dda.deltadist.x) * (ptr->dda.side == EW)) + \
	((ptr->dda.sidedist.y - ptr->dda.deltadist.y) * (ptr->dda.side == NS));
	fflush(stream_debug);
}

void draw_wall(t_raycast *ptr, int x){
	int lineh = (int)(HEIGHT/ (((int)ptr->dda.perpwalldist == 0) ? 1e20:ptr->dda.perpwalldist));
	int start, end;

	start = -lineh / 2 + HEIGHT/2;
	if(start < 0) start = 0;
		end = lineh / 2  + HEIGHT / 2;
	if(end >= HEIGHT) end = HEIGHT - 10;
		draw_line(ptr,(t_cord){x, start}, (t_cord){x, end}, 0xff00ff);
}

void	raycast(t_raycast *ptr){
	int x = 0;
	t_camera *cam;

	cam = &ptr->camera;
	cam->ray.origin = cam->pos;
	fprintf(stream_debug, "%f\t%f\n", ptr->camera.pos.cord.x, ptr->camera.pos.cord.y);
	fflush(stream_debug);
	debug_draw_map(ptr);
	while(x < WIDTH){
		ptr->camera.planx = (double)2 * x/ (double)WIDTH - (double)1;
		cam->ray.dir.cord.x = cam->dir.cord.x + cam->plane.cord.x * ptr->camera.planx;
		cam->ray.dir.cord.y = cam->dir.cord.y + cam->plane.cord.y * ptr->camera.planx;
		
		// dda(ptr);
		ultimate_dda(ptr);
		draw_wall(ptr, x);
		debug_draw_rays(ptr,cam->ray);
		x++;
	}
	mlx_put_image_to_window(ptr->ptr, ptr->ptr_win,ptr->img.img,0, 0);
}
