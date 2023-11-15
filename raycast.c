#include "raycastfs.h"


void debug_draw_ray(t_raycast *ptr, t_ray ray){
	int i = 0;
	while (i < 100){
		my_mlx_pixel_put(&ptr->img, ray.origin.cord.x + ray.dir.cord.x * i, ray.origin.cord.y + ray.dir.cord.y * i, 0x00FF0000);
		i++;
	}
}

void debug_draw_camera(t_raycast *ptr, t_vec2 *tab){
	
}


void init(t_vec2 **p){
	p[0]->cord = (t_cord){WIDTH / 2, HEIGHT / 2};
	p[1]->cord = (t_cord){-1, 0};
	p[2]->cord = (t_cord){-1, 0};
}

void	raycast(t_raycast *ptr){
	t_vec2 pos, dir, plane;
	t_vec2 *cords[3] = {&pos, &dir, &plane};
	init(cords);
	int x = 0;
	while(x < WIDTH){

		debug_draw_ray(ptr, (t_ray){pos, dir});
	}
	// debug_draw_camera(ptr, cords);
	mlx_put_image_to_window(ptr->ptr, ptr->ptr_win,ptr->img.img,0, 0);
}
