#ifndef RAYCASTFS_H
# define RAYCASTFS_H
#ifndef INC
#define INC 1
#endif
#if(INC)
	# include "/Users/redaghouzraf/Downloads/minilibx_opengl_20191021/mlx.h"
#else
	#include "mlx.h"
#endif
# include <stdlib.h>
# include <math.h>
# include <libc.h>
# include "ray.h"
# include <stdio.h>
# define WIDTH 700
# define HEIGHT 1000
# define MAP_H 10
# define MAP_W 7

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct	s_raycast {
	void *ptr;
	void *ptr_win;
	t_data img;
}t_raycast;
extern int map[MAP_H][MAP_W];
void read_map(t_raycast *data);
void clear_screen(t_raycast *ptr, unsigned int color);
void fillrec(t_raycast *ptr, t_cord begin ,t_cord end, int color);
void raycast(t_raycast *ptr);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
#endif