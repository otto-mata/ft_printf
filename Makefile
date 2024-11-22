LIBFT_ROOT=	libs/libft
SRC=		ft_utils.c \
			ft_printf.c \
			ft_count_flags.c \
			ft_display_formatted.c \
			ft_parse_flags.c \
			ft_parse_arg.c
OBJS=		$(patsubst %.c,%.o,$(SRCS))
NAME=		libftprintf.a

ARBIN=		ar
ARFLGS=		rcso

CC=			cc
CFLAGS=		-Wall -Wextra -Werror

$(NAME): libft.a $(OBJS)
	@mv libft.a $@ && $(ARBIN) $(ARFLGS) $@ $(OBJS)

%.o:%.c
	$(CC) -o $@ $^ -c $(CFLAGS) $(HEADERS)

libft.a:
	@cd $(LIBFT_ROOT) && make && mv libft.a ../../libft.a

clean:
	rm -f *.o
	rm -f libft.a

fclean: clean
	rm -f $(NAME)

re:	fclean all

all: $(NAME)

default: all

.PHONY: all re fclean clean