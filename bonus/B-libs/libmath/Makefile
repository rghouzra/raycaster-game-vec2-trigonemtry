# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rghouzra <rghouzra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/15 14:21:44 by rghouzra          #+#    #+#              #
#    Updated: 2024/01/17 22:22:05 by rghouzra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libmath.a

SRC = vector_utils.c evector_utils.c

INC = vector.h

OBJS = $(addprefix objs/, $(SRC:.c=.o))

FLAGS = -Wall -Wextra -Werror

$(NAME) : $(OBJS)
	@echo "compile libmath"
	@ar -rcs $(NAME) $(OBJS)

objs/%.o : %.c $(INC)
	@mkdir -p $(dir $@)
	@cc $(FLAGS) -c $< -o $@

all : $(NAME)

clean :
	@rm -rf objs

fclean : clean
	@echo "fclean libmath"
	@rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
