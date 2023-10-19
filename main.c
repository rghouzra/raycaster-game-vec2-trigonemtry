# include "raycastfs.h"

int map[MAP_H][MAP_W] = {
	{1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0},
	{1,0,0,1,0,0,0},
	{1,0,0,1,0,0,0},
	{1,0,0,0,0,1,0},
	{1,0,0,0,0,0,0},
	{1,0,0,0,0,0,0},
	{1,0,1,0,0,0,0},
	{1,0,0,0,0,0,0},
	{1,1,1,1,1,1,1},
};

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main()
{
	t_raycast *holder;

	holder = malloc(sizeof(t_raycast));
	if(!holder)
		return 1;
	holder->ptr = mlx_init();
	holder->ptr_win = mlx_new_window(holder->ptr, WIDTH, HEIGHT, "holder");
	holder->img.img = mlx_new_image(holder->ptr, WIDTH, HEIGHT);
	holder->img.addr = mlx_get_data_addr(holder->img.img, &holder->img.bits_per_pixel, \
	&holder->img.line_length, &holder->img.endian);
	mlx_put_image_to_window(holder->ptr, holder->ptr_win,holder->img.img, 0, 0);
	raycast(holder);
	mlx_loop(holder->ptr);
	free(holder);
	return 0;
}