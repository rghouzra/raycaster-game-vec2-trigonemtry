# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/04 00:21:06 by yrhiba            #+#    #+#              #
#    Updated: 2024/01/11 05:57:46 by yrhiba           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libgetnextline.a

SRC = get_next_line.c get_next_line_utils.c

INC = get_next_line.h

OBJS = $(addprefix objs/, $(SRC:.c=.o))

FLAGS = -Wall -Wextra -Werror

$(NAME) : $(OBJS)
	@echo "compile libgetnextline"
	@ar -rcs $(NAME) $(OBJS)

objs/%.o : %.c $(INC)
	@mkdir -p $(dir $@)
	@cc $(FLAGS) -c $< -o $@

all : $(NAME)

clean :
	@rm -rf objs

fclean : clean
	@echo "fclean libgetnextline"
	@rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
