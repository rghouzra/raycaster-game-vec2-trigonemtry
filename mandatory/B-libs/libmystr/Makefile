# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/02 19:51:46 by yrhiba            #+#    #+#              #
#    Updated: 2024/01/11 06:00:21 by yrhiba           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libmystr.a

SRCS =	my_string_append.c my_string_compare.c my_string_dup.c \
		my_string_join.c my_string_len.c my_string_size.c \
		my_string_update.c my_string_sub.c my_string_have.c \
		my_string_words_count.c my_string_split.c my_string_swap.c \
		my_strings_count.c my_strings_free.c my_strings_sort.c \
		my_string_find_last.c my_string_find_first.c \
		my_string_split_by_first.c my_strings_free_count.c \
		my_strings_dup_count.c my_string_append_char.c \
		my_string_replace_char.c my_string_isnumber.c \
		my_string_dup_strfill_with_char.c

INCS = libmystr.h

OBJSDIR = objs/
OBJS = $(addprefix $(OBJSDIR), $(SRCS:.c=.o))

FLAGS = -Wall -Wextra -Werror

$(NAME) : $(OBJS)
	@echo "compile libmystr"
	@ar -rcs $(NAME) $(OBJS)

$(OBJSDIR)%.o : %.c $(INCS)
	@mkdir -p $(dir $@)
	@cc $(FLAGS) -c $< -o $@

all : $(NAME)

clean :
	@rm -rf $(OBJSDIR)

fclean : clean
	@echo "fclean libmystr"
	@rm -rf $(NAME)

re : fclean all

.PHONEY : all re clean fclean
