#include "raycastfs.h"


void debug_draw_ray(t_raycast *ptr, t_ray ray){
	dda(ptr, ray.origin.cord, ray.dir.cord);
	mlx_put_image_to_window(ptr->ptr, ptr->ptr_win,ptr->img.img,0, 0);
}

void debug_draw_camera(t_raycast *ptr, t_vec2 *tab){
	
}


void init(t_vec2 **p){
	p[0]->cord = (t_cord){WIDTH / 2, HEIGHT / 2};
	p[1]->cord = (t_cord){1, 0};
	p[2]->cord = (t_cord){1, 0};
}

void	raycast(t_raycast *ptr){
	t_vec2 pos, dir, plane;
	t_ray ray;
	t_vec2 *cords[3] = {&pos, &dir, &plane};
	double planx;
	init(cords);
	int x = 0;
	while(x < WIDTH){
		planx = ((2 * x) / WIDTH) - 1;
		ray.origin = pos;
		ray.dir.cord.x = dir.cord.x + (plane.cord.x * planx);
		ray.dir.cord.y = dir.cord.y + (plane.cord.y * planx);
		debug_draw_ray(ptr, (t_ray){pos, dir});
		x++;
	}
	// debug_draw_camera(ptr, cords);
	mlx_put_image_to_window(ptr->ptr, ptr->ptr_win,ptr->img.img,0, 0);
}
