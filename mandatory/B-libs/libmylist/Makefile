# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/09 11:25:44 by yrhiba            #+#    #+#              #
#    Updated: 2024/01/11 05:59:49 by yrhiba           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libmylist.a

OBJFLAGS = -Wall -Wextra -Werror

SRCS =	my_list_init.c \
		my_list_clear.c \
		my_list_new_elem.c \
		my_list_push_back.c \
		my_list_push_front.c \
		my_list_front.c \
		my_list_back.c \
		my_list_empty.c \
		my_list_size.c \
		my_list_pop_front.c \
		my_list_pop_back.c \
		my_list_get.c \
		my_list_erase.c \
		my_list_insert.c

INC = my_list.h

ODIR = objs/
OBJS = $(addprefix $(ODIR), $(SRCS:.c=.o))

$(NAME) : $(OBJS)
	@echo "compile libmylist"
	@ar -rcs $(NAME) $(OBJS)

all : $(NAME)

$(ODIR)%.o : %.c $(INC)
	@mkdir -p $(ODIR)
	@cc $(OBJFLAGS) -c $< -o $@

clean :
	@rm -rf $(ODIR)

fclean : clean
	@echo "fclean libmylist"
	@rm -rf $(NAME)

re : fclean all

.PHONEY : all fclean clean re
