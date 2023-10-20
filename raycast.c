#include "raycastfs.h"

void init(t_vec2 *pos, t_vec2 *dir, t_vec2 *plane){
	pos->cord.x = 22;
	pos->cord.y = 12;
	dir->cord.x = -1;
	dir->cord.y = 0;
	plane->cord.x = 0;
	plane->cord.y = 0.66;
}

void dda(){
	double x1 = 10,y1 = 10;
	double x2 = 400,y2 = 400;
	double dx = x2 - x1, dy = y2 - y1;
	
}

void	raycast(t_raycast *ptr){
	int x;
	t_vec2 pos, dir, plane;
	
	dda();
	return ;
	init(&pos,&dir,&plane);
	x = 0;
	while (x < WIDTH){
		t_vec2 ray;
		double camx;
		camx = ((2 * x)/(double)WIDTH) - 1;
		ray.cord.x = dir.cord.x + (camx * plane.cord.x);
		ray.cord.y = dir.cord.y + (camx * plane.cord.y);

		x++;
	}
	mlx_put_image_to_window(ptr->ptr, ptr->ptr_win,ptr->img.img,0, 0);
}
