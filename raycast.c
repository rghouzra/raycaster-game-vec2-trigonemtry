#include "raycastfs.h"


void debug_draw_ray(t_raycast *ptr, t_ray ray){
	static int i;
	i++;
	if(i < 20)
		return;
	i= 0;
	dda(ptr, ray.origin.cord, op_two_vectors(ray.origin, scaleVec(ray.dir, WIDTH + HEIGHT), ADD).cord, 0xff);
}

void debug_draw_camera(t_raycast *ptr, t_vec2 *tab){
	
}


void init(t_vec2 **p){
	p[0]->cord = (t_cord){WIDTH / 2, HEIGHT / 2};
	p[1]->cord = (t_cord){-1, 0};
	p[2]->cord = (t_cord){0, 0.66};
}


void debug_draw_player(t_raycast *ptr, t_vec2 **t){
	dda(ptr,(t_cord){0,0}, t[0]->cord, 0x00FF10);
}

void debug_draw_map(t_raycast *p){
	int i, j;
	i = 0;
	while(i < MAP_H){
		j = 0;
		while(j < MAP_W){
			if(map[i][j] == 1){
				fillrec(p, (t_cord){
					.x = j*( WIDTH - 300)/ 10,
					.y = i*(HEIGHT - 350)/ 10
					},
					(t_cord){
					.x = j*( WIDTH - 300)/ 10 +( WIDTH - 300)/10,
					.y =   i*(HEIGHT - 350)/ 10 + (HEIGHT - 350) / 10
					} , 0xFFFFFF);
			}
			else
				fillrec(p, (t_cord){
					.x = j*( WIDTH - 300)/ 10,
					.y = i*(HEIGHT - 350)/ 10
					},
					(t_cord){
					.x = j*( WIDTH - 300)/ 10 +( WIDTH - 300)/10,
					.y =   i*(HEIGHT - 350)/ 10 + (HEIGHT - 350) / 10
					} , 0x0);
			j++;
		}
		i++;
	}
}

void draw_ray(t_raycast *ptr){
	(void)ptr;
}

void ultimate_dda(t_raycast *ptr){
	
}

void	raycast(t_raycast *ptr){
	int x = 0;
	t_camera *cam;

	cam = &ptr->camera;
	cam->ray.origin = cam->pos;
	debug_draw_map(ptr);
	debug_draw_player(ptr, (t_vec2 *[]){&cam->pos, &cam->dir, &cam->plane});
	while(x < WIDTH){
		ptr->camera.planx = (double)2 * x/ (double)WIDTH - (double)1;
		cam->ray.dir.cord.x = cam->dir.cord.x + cam->plane.cord.x * ptr->camera.planx;
		cam->ray.dir.cord.y = cam->dir.cord.y + cam->plane.cord.y * ptr->camera.planx;
		// debug_draw_ray(ptr, cam->ray);
		ultimate_dda(ptr);
		x++;
	}
	mlx_put_image_to_window(ptr->ptr, ptr->ptr_win,ptr->img.img,0, 0);
}
