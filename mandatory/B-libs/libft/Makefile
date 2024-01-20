NAME = libft.a

SRCS = 	ft_atoi.c\
		ft_bzero.c\
		ft_calloc.c\
		ft_itoa.c\
		ft_putnbr.c\
		ft_memcmp.c\
		ft_strncmp.c\
		ft_split.c\
		ft_striteri.c\
		ft_strdup.c\
		ft_strlcat.c\
		ft_strlcpy.c\
		ft_strlen.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_memchr.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_memset.c\
		ft_strchr.c\
		ft_strjoin.c\
		ft_strncmp.c\
		ft_strnstr.c\
		ft_tolower.c\
		ft_toupper.c\
		ft_strrchr.c\
		ft_lstmap.c\
		ft_strmapi.c\
		ft_strtrim.c\
		ft_substr.c\
		ft_putchar_fd.c\
		ft_putendl_fd.c\
		ft_putendl.c\
		ft_putnbr_fd.c\
		ft_putstr_fd.c\
		sysfunc_wrapper.c\
		ft_lstadd_back.c\
		ft_lstadd_front.c\
		ft_lstclear.c\
		ft_lstdelone.c\
		ft_lstiter.c\
		ft_lstlast.c\
		ft_lstnew.c\
		ft_lstsize.c\
		ft_lstmap.c

OBJECTS = ${SRCS:.c=.o}

HEADER = libft.h

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all:$(NAME)

$(NAME) : $(OBJECTS)
	@echo "compile libft"
	@ar -rcs $(NAME) $(OBJECTS)

%.o : %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $<

clean:
	@$(RM) ${OBJECTS} ${BONUS_OBJECTS}

fclean: clean
	@echo "fclean libft"
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
