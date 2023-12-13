#ifndef RAYCASTFS_H
# define RAYCASTFS_H
#ifndef __x86_64 
#define __x86_64 0
#endif
#ifndef INC
#define INC !__x86_64
#endif
#if(INC)
	# include "/Users/redaghouzraf/Downloads/minilibx_opengl_20191021/mlx.h"
#else
	#include "mlx.h"
#endif
# include <stdlib.h>
# include <libc.h>
# include <math.h>
# include <stdbool.h>
# include "ray.h"
# include <stdio.h>
# define abs(N)((N > 0) ? (N) : (-N))
# define WIDTH 800
# define HEIGHT 800
# define MAP_H 20
#define GSIZE 10
# define MAP_W 20
# define degree_to_rad(x)((x) * M_PI / 180.0)
# define NS 1
# define EW 0
typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_camera{
	t_vec2 pos;
	t_vec2 dir;
	t_ray ray;
	t_vec2 plane;
	double planx;
}t_camera;

typedef struct s_dda{
	t_cord deltadist;
	t_cord sidedist;
	double perpwalldist;
	int stepx, stepy;
	int mapx, mapy;
	int hit;
	t_camera camera;
	int side;
}t_dda;

typedef struct	s_raycast {
	void *ptr;
	void *ptr_win;
	t_camera camera;
	t_dda dda;
	t_data img;
}t_raycast;



extern int map[MAP_H][MAP_W];
extern FILE *stream_debug;

void read_map(t_raycast *data);
int key_press(int keycode, void *p);
void clear_screen(t_raycast *ptr, unsigned int color);
void fillrec(t_raycast *ptr, t_cord begin ,t_cord end, int color);
void fillrecborders(t_raycast *ptr, t_cord begin ,t_cord end, int color);
void raycast(t_raycast *ptr);
void draw_line(t_raycast *ptr, t_cord begin, t_cord end, int color);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
#endif
