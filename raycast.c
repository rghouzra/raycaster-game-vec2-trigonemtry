#include "raycastfs.h"


void debug_draw_ray(t_raycast *ptr, t_ray ray){
	static int i;
	i++;
	if(i < 20)
		return;
	i= 0;
	dda(ptr, ray.origin.cord, op_two_vectors(ray.origin, scaleVec(ray.dir, 300), ADD).cord, 0xff);
}

void debug_draw_camera(t_raycast *ptr, t_vec2 *tab){
	
}


void init(t_vec2 **p){
	p[0]->cord = (t_cord){WIDTH / 2, HEIGHT / 2};
	p[1]->cord = (t_cord){-1, 0};
	p[2]->cord = (t_cord){0, 0.66};
}


void debug_draw_player(t_raycast *ptr, t_vec2 **t){
	dda(ptr,(t_cord){0,0}, t[0]->cord, 0x00FF00);
}

void	raycast(t_raycast *ptr){
	t_vec2 pos, dir, plane;
	t_ray ray;
	t_vec2 *cords[3] = {&pos, &dir, &plane};
	double planx;
	pos = ptr->camera.pos;
	dir = ptr->camera.dir;
	plane = ptr->camera.plane;
	int x = 0;
	ray.origin = pos;
	// debug_draw_player(ptr, cords);
	// dda(ptr,(t_cord){WIDTH/2, HEIGHT/2}, (t_cord){0, HEIGHT-1}, 0x0000ff);
	while(x < WIDTH){
		planx = (double)2 * x/ (double)WIDTH - (double)1;
		ray.dir.cord.x = dir.cord.x + plane.cord.x * planx;
		ray.dir.cord.y = dir.cord.y + plane.cord.y * planx;
		debug_draw_ray(ptr, ray);
		x++;
	}
	mlx_put_image_to_window(ptr->ptr, ptr->ptr_win,ptr->img.img,0, 0);
	// debug_draw_camera(ptr, cords);
}
