#!/bin/bash

if [ "$1" == "clean" ]; then
	echo cleaning...
	rm -rf executable
else
	echo compiling...
	export bool="false"
	if [ $(users) == "redaghouzraf" ]; then
		export bool="true"
		cp /Users/redaghouzraf/Downloads/minilibx_opengl_20191021/libmlx.a .
		export FLAGS="-framework OpenGL -framework  AppKit -framework GLUT -lm"
		export lib="libmlx.a"
		export inc="-I /Users/redaghouzraf/Downloads/minilibx_opengl_20191021/"
	fi
	if [ $(uname) == "Darwin" ]; then
		echo "working"
		export FLAGS="-framework OpenGL -framework  AppKit -framework GLUT -lm"
		if [ $bool == "false" ]; then
			export FLAGS+=" -lmlx -DINC=0"
		fi
	fi
	clang -fsanitize=address main.c raycast.c ray_utils.c draw_utils.c vector_utils.c $inc $lib $FLAGS -o executable
	unset FLAGS
	unset inc
	unset lib
fi
