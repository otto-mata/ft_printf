SRC=ft_specialjoin.c \
	ft_strrev.c \
	ft_printf.c \
	ft_itoa_base.c \
	ft_itoa_base_int.c \
	ft_itoa.c \
	ft_char_in_s.c \
	ft_bzero.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_strncmp.c \
	ft_calloc.c \
	ft_strlen.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_strdup.c \
	ft_strjoin.c \
	ft_parse_flags.c \
	ft_parse_arg.c \
	ft_count_flags.c \
	ft_display_formatted.c

OBJS=		$(SRC:.c=.o)
NAME=		libftprintf.a

ARBIN=		ar
ARFLGS=		rcs

CC=			cc
CFLAGS=		-Wall -Wextra -Werror

$(NAME): $(OBJS)
	$(ARBIN) $(ARFLGS) $@ $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

all: $(NAME)

default: all

.PHONY: all re fclean clean