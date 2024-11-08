NAME		=	libftprintf.a
LIB			=	ar rcs
RM			=	rm -f
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror

SRCS		=	ft_printf.c \
				ft_printf_utils.c

SRCS_BONUS	=	ft_printf_bonus.c \
				ft_printf_flags_bonus.c \
				ft_printf_utils_bonus.c \
				ft_printf_len_bonus.c \
				ft_printf_lib_bonus.c \
				ft_printf_put_bonus.c \
				ft_printf_chr_bonus.c \
				ft_printf_hex_bonus.c \
				ft_printf_nbr_bonus.c \
				ft_printf_ptr_bonus.c \
				ft_printf_unbr_bonus.c

OBJS		=	$(SRCS:.c=.o)
OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)

INCLUDES	=	ft_printf.h ft_printf_bonus.h

all:		$(NAME)

$(NAME):	$(OBJS)
			$(LIB) $(NAME) $(OBJS)

bonus:		$(OBJS_BONUS)
			$(LIB) $(NAME) $(OBJS_BONUS)

%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
			$(RM) $(OBJS) $(OBJS_BONUS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all bonus sclean fclean re