# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 00:12:42 by yrhiba            #+#    #+#              #
#    Updated: 2024/01/17 15:10:03 by yrhiba           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS =	main.c \
		0-data-module/init_data.c \
		0-data-module/clear_data.c \
		0-data-module/init_sprites.c \
		1-frame-module/frame_pixel_put.c \
		1-frame-module/frame_fill_with_color.c \
		1-frame-module/frame_update.c \
		1-frame-module/frame_render_rect.c \
		1-frame-module/frame_render_line.c \
		1-frame-module/frame_get_color.c \
		1-frame-module/frame_render_sprite.c \
		2-mlx-module/init_mlx.c \
		2-mlx-module/events/keypressdown.c \
		2-mlx-module/events/keypressdup.c \
		2-mlx-module/events/redcrosspressed.c \
		2-mlx-module/events/mousemove.c \
		2-mlx-module/events/mousedown.c \
		2-mlx-module/events/mouseup.c \
		3-parsing-module/do_parsing.c \
		3-parsing-module/read_file_content.c \
		3-parsing-module/check_line.c \
		3-parsing-module/clear_parsing_data.c \
		3-parsing-module/construct_map.c \
		3-parsing-module/check_for_map.c \
		3-parsing-module/set_player_data.c \
		3-parsing-module/load_textures.c \
		3-parsing-module/check_for_map_2.c \
		3-parsing-module/check_line_2.c \
		3-parsing-module/do_parsing_2.c \
		4-game-module/update_player.c \
		4-game-module/update_sprites.c \
		4-game-module/update_minmap.c \
		4-game-module/update_doors.c \
		4-game-module/render_2dmap.c \
		4-game-module/render_2dallrays.c \
		4-game-module/render_player_in2dmap.c \
		4-game-module/render_3d_projections.c \
		4-game-module/reneder_minmap.c \
		4-game-module/render_floor_cilling.c \
		4-game-module/render_footer.c \
		4-game-module/render_sprites.c \
		5-raycasting-module/cast_all_rays.c \
		5-raycasting-module/cast_all_rays_2.c \
		5-raycasting-module/cast_all_rays_3.c \
		A-utils/getcolor.c \
		A-utils/exit_failure.c \
		A-utils/check_ext.c \
		A-utils/my_string_free.c \
		A-utils/is_valid_color.c \
		A-utils/dumy_math.c \
		A-utils/set_and_free_directions.c \
		A-utils/isplauyercolliedwithwall.c \
		A-utils/is_valid_map_pos.c \
		A-utils/door_util.c

INC =	header.h

LIBS =	B-libs/libft/libft.a \
		B-libs/libgetnextline/libgetnextline.a \
		B-libs/libmylist/libmylist.a \
		B-libs/libmystr/libmystr.a

OBJS_INCS = -I. \
			-I B-libs/libft \
			-I B-libs/libgetnextline \
			-I B-libs/libmylist \
			-I B-libs/libmystr

OBJS = $(SRCS:.c=.o)

CC = cc

FLAGS = -Wall -Wextra #-g -fsanitize=address

MLX_DEPENDS = -lm -lmlx -framework OpenGL -framework AppKit

all :
	make make_libs
	make $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $(MLX_DEPENDS) $(OBJS) $(LIBS) -o $(NAME)

%.o : %.c $(INC) $(LIBS)
	$(CC) $(FLAGS) $(OBJS_INCS) -c $< -o $@

clean : clean_libs
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

make_libs:
	make -C B-libs/libft
	make -C B-libs/libgetnextline
	make -C B-libs/libmylist
	make -C B-libs/libmystr

clean_libs:
	make fclean -C B-libs/libft
	make fclean -C B-libs/libgetnextline
	make fclean -C B-libs/libmylist
	make fclean -C B-libs/libmystr

.PHONY : all clean fclean re make_libs clean_libs
