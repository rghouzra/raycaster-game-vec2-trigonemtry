#include "raycastfs.h"

void init(t_vec2 *pos, t_vec2 *dir, t_vec2 *plane){
	pos->cord.x = 22;
	pos->cord.y = 12;
	dir->cord.x = -1;
	dir->cord.y = 0;
	plane->cord.x = 0;
	plane->cord.y = 0.66;
}

void dda(t_raycast *p, double x1, double y1,double x2,  double y2){
	double dx = x2 - x1, dy = y2 - y1;
	double steps = (fabs(dx) > fabs(dy) ) ? dx : dy;
	// if(steps == 0)
	// 	return ;
	double xinc = dx / steps;
	double yinc = dy / steps;
	for(int i = 0; i < steps; i++){
		my_mlx_pixel_put(&p->img, x1, y1, 0x00ff00);
		// printf("%f\t%f\n", x1, y1);
		x1+=xinc;
		y1+=yinc;
	}
}

void	raycast(t_raycast *ptr){
	int x;
	t_vec2 pos, dir, plane;

	// init(&pos,&dir,&plane);
	for(int i = 0; i <MAP_H;i++){
		for (size_t j = 0; j < MAP_H; j++)
		{
			if(map[i][j] == 1)  fillrec(ptr, (t_cord){j*16, i*16},(t_cord){16, 16}, 0x1ff );
		}
		
	}
	mlx_put_image_to_window(ptr->ptr, ptr->ptr_win, ptr->img.img, 0, 0);
	return ;
	x = 0;
	while (x < WIDTH){
		t_vec2 ray;
		double camx;
		camx = ((2 * x)/(double)WIDTH) - 1;
		printf("%f\t%f\n", ray.cord.x, ray.cord.y);
		ray.cord.x = dir.cord.x + (camx * plane.cord.x);
		ray.cord.y = dir.cord.y + (camx * plane.cord.y);
		// dda(ptr, 0, 0, x , x);
		x++;
	}
	mlx_put_image_to_window(ptr->ptr, ptr->ptr_win,ptr->img.img,0, 0);
}
