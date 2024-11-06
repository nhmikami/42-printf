NAME		=	libftprintf.a
LIB			=	ar rcs
RM			=	rm -f
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror

SRCS		=	ft_printf.c ft_printf_utils.c
OBJS		=	$(SRCS:.c=.o)

INCLUDES	=	ft_printf.h

all:		$(NAME)

$(NAME):	$(OBJS)
			$(LIB) $(NAME) $(OBJS)

%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all sclean fclean re