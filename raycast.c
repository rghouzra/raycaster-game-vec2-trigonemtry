#include "raycastfs.h"

void init(t_vec2 *pos, t_vec2 *dir, t_vec2 *plane){
	pos->cord.x = 22;
	pos->cord.y = 12;
	dir->cord.x = -1;
	dir->cord.y = 0;
	plane->cord.x = 0;
	plane->cord.y = 0.66;
}

void	raycast(t_raycast *ptr){
	int x;
	t_vec2 pos, dir, plane;
	
	init(&pos,&dir,&plane);
	x = 0;
	while (x < WIDTH){
		my_mlx_pixel_put(&ptr->img, x, 0,0x00+x* 10);
		x++;
	}
	mlx_put_image_to_window(ptr->ptr, ptr->ptr_win,ptr->img.img,0, HEIGHT / 2);
}
