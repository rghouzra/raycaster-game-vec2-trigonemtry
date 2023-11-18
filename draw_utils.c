#include "raycastfs.h"

void dda(t_raycast *ptr, t_cord begin, t_cord end, int color){
	double dx, dy;
	double m;
	double xinc, yinc;
	int i, steps;

	dx = (end.x - begin.x);
	dy = (end.y - begin.y);
	if(abs(dy) > abs(dx)){
		xinc = dx / (double)abs(dy);
		yinc = dy / (double)abs(dy);
		steps = abs(dy);
	}else{
		steps = abs(dx);
		xinc = dx / (double)abs(dx);
		yinc = dy / (double)abs(dx);
	}
	i = 0;
	static int j;
	while(i <= steps){
		my_mlx_pixel_put(&ptr->img, round(begin.x), round(begin.y), color);
		// printf("%f\t%f\n", begin.x, begin.y);
		begin.x +=xinc;
		begin.y +=yinc;
		i++;
	}
}

void fillrec(t_raycast *ptr, t_cord begin ,t_cord end, int color){
	for(int i = begin.y; i < end.y; i++){
		for (size_t j = begin.x; j < end.x; j++)
		{
			my_mlx_pixel_put(&ptr->img, j, i, color);
		}
	}
	mlx_put_image_to_window(ptr->ptr, ptr->ptr_win, ptr->img.img, 0, 0);
}

void clear_screen(t_raycast *ptr, unsigned int color){
	for(int i = 0; i < HEIGHT; i++){
		for (size_t j = 0; j < WIDTH; j++){
			my_mlx_pixel_put(&ptr->img, j, i, color);
		}
	}
	mlx_put_image_to_window(ptr->ptr, ptr->ptr_win, ptr->img.img, 0, 0);
}
