# include "raycastfs.h"

int map[MAP_H][MAP_W] = {
	{1,1,1,1,1,1,1},
	{1,0,0,0,1,0,1},
	{1,0,0,1,1,1,1},
	{1,0,0,1,1,0,1},
	{1,0,1,1,1,1,1},
	{1,0,1,1,1,0,1},
	{1,0,1,1,1,0,1},
	{1,0,1,1,1,0,1},
	{1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1},
};

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	if(x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void clear(t_raycast *h, int color)
{
	for (size_t i = 0; i < HEIGHT; i++)
	{
		for (size_t j = 0; j< WIDTH;j++){
			my_mlx_pixel_put(&h->img, j, i, color);
		}
	}
	mlx_put_image_to_window(h->ptr, h->ptr_win,h->img.img,0, 0);
}

void init_camera(t_camera *camera){
	camera->pos.cord = (t_cord){3,1};
	camera->dir.cord = (t_cord){1, 0};
	camera->plane = rotate_vec(camera->dir,  degree_to_rad(90));
	if(camera->plane.cord.x >0.0001 || camera->plane.cord.x < -0.00011)
		camera->plane.cord.x -=  ((camera->plane.cord.x >= 0) * 0.34 ) + ((camera->plane.cord.x < 0) * -0.34);
	if(camera->plane.cord.y>0.0001 || camera->plane.cord.y< -0.0001)
		camera->plane.cord.y -=  ((camera->plane.cord.y >= 0) * 0.34 ) + ((camera->plane.cord.y < 0) * -0.34);
}

int mouse_press(int button, int x, int y, void *p){
	(void)button;
	(void)x;
	(void)y;
	t_raycast *ptr = (t_raycast *)p;
	ptr->camera.pos.cord = (t_cord){x, y};
	clear_screen(ptr, 0x0);
	raycast(ptr);
	return 0;
}
FILE *stream_debug;

int main()
{
	t_raycast *holder;

	stream_debug = fopen("debug.txt", "w");
	if(!stream_debug)
	{
		perror("fopen: ");
		exit(1);
	}
	holder = calloc(sizeof(t_raycast) + 1, 1);
	if(!holder)
		return 1;
	holder->ptr = mlx_init();
	holder->ptr_win = mlx_new_window(holder->ptr, WIDTH, HEIGHT, "holder");
	holder->img.img = mlx_new_image(holder->ptr, WIDTH, HEIGHT);
	holder->img.addr = mlx_get_data_addr(holder->img.img, &holder->img.bits_per_pixel, \
	&holder->img.line_length, &holder->img.endian);
	init_camera(&holder->camera);
	raycast(holder);
	mlx_key_hook(holder->ptr_win, key_press, holder);
	// mlx_mouse_hook(holder->ptr_win, mouse_press, holder);
	mlx_loop(holder->ptr);
	free(holder);
	fclose(stream_debug);
	return 0;
}
