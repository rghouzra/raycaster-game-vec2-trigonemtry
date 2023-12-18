#include "raycastfs.h"

int key_press(int keycode, void *p){
	t_raycast *ptr = (t_raycast *)p;
	int b;

	b = 0;
	if(keycode == 53)
		exit(0);
	if(keycode == 13){
		if(ptr->camera.pos.cord.y>0){
			if(map[(int)ptr->camera.pos.cord.y - 1][(int)ptr->camera.pos.cord.x] == 0)
			{
				ptr->camera.pos.cord.y -= 1;
				b = 1;
			}
		}
	}
	if(keycode == 1){
		if(ptr->camera.pos.cord.y < MAP_H - 2)
			if(map[(int)ptr->camera.pos.cord.y + 1][(int)ptr->camera.pos.cord.x] == 0)
			{
				ptr->camera.pos.cord.y += 1;
				b = 1;
			}
	}
	if(keycode == 0){
		if(ptr->camera.pos.cord.x > 0)
			if(map[(int)ptr->camera.pos.cord.y ][(int)ptr->camera.pos.cord.x - 1] == 0)
			{
				ptr->camera.pos.cord.x -= 1;
				b = 1;
			}
	}
	if(keycode == 2){
		if(ptr->camera.pos.cord.x < MAP_W - 2)
			if(map[(int)ptr->camera.pos.cord.y ][(int)ptr->camera.pos.cord.x + 1] == 0)
			{
				ptr->camera.pos.cord.x += 1;
				b = 1;
			}
	}
	if(keycode == 123){
		ptr->camera.dir = rotate_vec(ptr->camera.dir, degree_to_rad(-10));
		ptr->camera.plane = rotate_vec(ptr->camera.plane, degree_to_rad(-10));
		b = 1;
	}
	if(keycode == 124){
		ptr->camera.plane = rotate_vec(ptr->camera.plane, degree_to_rad(10));
		 ptr->camera.dir = rotate_vec(ptr->camera.dir, degree_to_rad(10));
		 b = 1;
	}
	// if(keycode == 126){
	// 	if(ptr->camera.pos.cord.x >= 20)
	// 	ptr->camera.pos.cord.y -= 1;
	// }
	// if(keycode == 125){
	// 	if(ptr->camera.pos.cord.x < HEIGHT - 20)
	// 	ptr->camera.pos.cord.y += 1;
	// }
	if(b)
	{
		clear_screen(ptr, 0x000000);
		raycast(ptr);
	}
	return 0;
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