#include "raycastfs.h"

int key_press(int keycode, void *p){
	t_raycast *ptr = (t_raycast *)p;
	if(keycode == 53)
		exit(0);
	if(keycode == 13){
		if(ptr->camera.pos.cord.y > 11){

			ptr->camera.pos.cord.y -= 18;
		}
	}
	if(keycode == 1){
		if(ptr->camera.pos.cord.y < HEIGHT - 11)
			ptr->camera.pos.cord.y += 18;
	}
	if(keycode == 0){
		if(ptr->camera.pos.cord.x > 11)
			ptr->camera.pos.cord.x -= 18;
	}
	if(keycode == 2){
		if(ptr->camera.pos.cord.x < WIDTH - 11)
			ptr->camera.pos.cord.x += 18;
	}
	if(keycode == 123){
		ptr->camera.dir = rotate_vec(ptr->camera.dir, degree_to_rad(-25));
		ptr->camera.plane = rotate_vec(ptr->camera.plane, degree_to_rad(-25));
	}
	if(keycode == 124){
		ptr->camera.plane = rotate_vec(ptr->camera.plane, degree_to_rad(25));
		 ptr->camera.dir = rotate_vec(ptr->camera.dir, degree_to_rad(25));
	}
	if(keycode == 126){
		if(ptr->camera.pos.cord.x >= 20)
		ptr->camera.pos.cord.y -= 20;
	}
	if(keycode == 125){
		if(ptr->camera.pos.cord.x < HEIGHT - 20)
		ptr->camera.pos.cord.y += 20;
	}
	clear_screen(ptr, 0x000000);
	raycast(ptr);
	return 0;
}