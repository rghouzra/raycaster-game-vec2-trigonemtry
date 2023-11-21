#include "raycastfs.h"

void dda(t_raycast *ptr, t_cord begin, t_cord end, int color){
	double dx, dy;
	double xinc, yinc;
	int i, steps;

	dx = (end.x - begin.x);
	dy = (end.y - begin.y);
	if(fabs(dy) > fabs(dx)){
		xinc = dx / (double)fabs(dy);
		yinc = dy / (double)fabs(dy);
		steps = fabs(dy);
	}else{
		steps = fabs(dx);
		xinc = dx / (double)fabs(dx);
		yinc = dy / (double)fabs(dx);
	}
	i = 0;
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
			if((i >= begin.y && i <=begin.y) || (i >= end.y && i < begin.y ) ||\
			(j >= begin.x && j <= begin.x) || (j >= end.x  && j < begin.x) )
			my_mlx_pixel_put(&ptr->img, j, i, 0xff0000);
			else
				my_mlx_pixel_put(&ptr->img, j, i, color);
		}
	}
	mlx_put_image_to_window(ptr->ptr, ptr->ptr_win, ptr->img.img, 0, 0);
}

void fillrecborders(t_raycast *ptr, t_cord begin ,t_cord end, int color){
	for(int i = begin.y; i < end.y; i++){
		for (size_t j = begin.x; j < end.x; j++)
		{
			if((i >= begin.y && i <=begin.y) || (i >= end.y && i < begin.y ) ||\
			(j >= begin.x && j <= begin.x) || (j >= end.x  && j < begin.x) )
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
