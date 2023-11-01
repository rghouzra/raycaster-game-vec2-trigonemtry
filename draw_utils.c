#include "raycastfs.h"


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
		for (size_t j = 0; j < WIDTH; j++)
		{
			my_mlx_pixel_put(&ptr->img, j, i, color);
		}
	}
	mlx_put_image_to_window(ptr->ptr, ptr->ptr_win, ptr->img.img, 0, 0);
}