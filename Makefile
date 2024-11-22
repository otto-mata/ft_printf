LIBFT_ROOT=	libs/libft
SRC=		ft_utils.c \
			ft_printf.c \
			ft_count_flags.c \
			ft_display_formatted.c \
			ft_parse_flags.c \
			ft_parse_arg.c

OBJS=		$(SRC:.c=.o)
NAME=		libftprintf.a

ARBIN=		ar
ARFLGS=		rcso

CC=			cc
CFLAGS=		-Wall -Wextra -Werror

$(NAME): libft.a $(OBJS)
	@mv libft.a $@ && $(ARBIN) $(ARFLGS) $@ $(OBJS)

.c.o:
	$(CC) -c $(HEADERS) $^ $(CFLAGS) -o ${<:.c=.o}

libft.a:
	@make -C $(LIBFT_ROOT) && cp $(LIBFT_ROOT)/libft.a .

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	@make fclean -C $(LIBFT_ROOT)

re:	fclean all

all: $(NAME)

default: all

.PHONY: all re fclean clean .c.o