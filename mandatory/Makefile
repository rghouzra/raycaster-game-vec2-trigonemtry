# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 00:12:42 by yrhiba            #+#    #+#              #
#    Updated: 2024/01/18 11:31:36 by yrhiba           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS =	main.c \
		0-data-module/init_data.c \
		0-data-module/clear_data.c \
		1-frame-module/frame_pixel_put.c \
		1-frame-module/frame_fill_with_color.c \
		1-frame-module/frame_update.c \
		1-frame-module/frame_render_rect.c \
		1-frame-module/frame_get_color.c \
		2-mlx-module/init_mlx.c \
		2-mlx-module/events/keypressdown.c \
		2-mlx-module/events/keypressdup.c \
		2-mlx-module/events/redcrosspressed.c \
		3-parsing-module/do_parsing.c \
		3-parsing-module/read_file_content.c \
		3-parsing-module/check_line.c \
		3-parsing-module/clear_parsing_data.c \
		3-parsing-module/construct_map.c \
		3-parsing-module/check_for_map.c \
		3-parsing-module/set_player_data.c \
		3-parsing-module/load_textures.c \
		3-parsing-module/do_parsing_2.c \
		3-parsing-module/check_for_map_2.c \
		3-parsing-module/check_line_2.c \
		4-game-module/update_player.c \
		5-raycasting-module/cast_all_rays.c \
		A-utils/getcolor.c \
		A-utils/exit_failure.c \
		A-utils/check_ext.c \
		A-utils/my_string_free.c \
		A-utils/is_valid_color.c \
		A-utils/dumy_math.c \
		A-utils/set_and_free_directions.c \
		A-utils/isplauyercolliedwithwall.c \
		A-utils/is_valid_map_pos.c \
		A-utils/degtorad.c \
		A-utils/door_util.c \
		A-utils/getwhichtext.c \

INC =	header.h

LIBS =	B-libs/libft/libft.a \
		B-libs/libgetnextline/libgetnextline.a \
		B-libs/libmylist/libmylist.a \
		B-libs/libmystr/libmystr.a \
		B-libs/libmath/libmath.a

OBJS_INCS = -I. \
			-I B-libs/libft \
			-I B-libs/libgetnextline \
			-I B-libs/libmylist \
			-I B-libs/libmystr \
			-I B-libs/libmath

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
	make -C B-libs/libmath

clean_libs:
	make fclean -C B-libs/libft
	make fclean -C B-libs/libgetnextline
	make fclean -C B-libs/libmylist
	make fclean -C B-libs/libmystr
	make fclean -C B-libs/libmath

.PHONY : all clean fclean re make_libs clean_libs
