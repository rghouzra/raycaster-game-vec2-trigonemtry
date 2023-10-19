#!/bin/bash

if [ "$1" == "clean" ]; then
	echo cleaning...
	rm -rf executable
else
	echo compiling...
	export FLAGS="-framework OpenGL -framework  AppKit -framework GLUT -lm"
	export lib="libmlx.a"
	export inc="-I /Users/redaghouzraf/Downloads/minilibx_opengl_20191021/"
	if [ $(uname) == "Darwin" ]; then
		echo "working"
		unset inc
		unset lib
		export FLAGS="-framework OpenGL -framework  AppKit -framework GLUT -lm -lmlx -fsanitize=signed-integer-overflow"
	fi
	clang main.c raycast.c ray_utils.c vector_utils.c $lib $FLAGS -o executable
	unset FLAGS
	unset inc
	unset lib
fi
