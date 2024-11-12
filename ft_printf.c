/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 20:01:13 by tblochet          #+#    #+#             */
/*   Updated: 2024/11/12 23:10:00 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft/libft.h"

typedef enum FlagType {
	F_CHR,
	F_STR,
	F_PTR,
	F_INT,
	F_UIN,
	F_HEX,
	F_HEXU,
	F_ESC,
}			t_flag_type;

typedef struct s_flag_var
{
	t_flag_type		flag;
	int				int_;
	unsigned int	uint_;
	char			*str_;
	unsigned long	ulong_;
}			t_flag_var;

typedef struct s_string_stats
{
	size_t				total_sz;
	size_t				const_sz;
	size_t				flag_cnt;
	struct s_flag_var	*flag_var_arr;
}				t_string_stats;

int	ft_char_in_s(char c, char const *s)
{
	while (*s)
		if (c == *s++)
			return (1);
	return (0);
}

void	ft_putnbrhex(unsigned int nbr, int fd)
{
	long const	base_len = 16;
	long int	n_as_long;
	char const	*base = "0123456789abcdef";

	n_as_long = nbr;
	if (n_as_long >= base_len)
		ft_putnbrhex(n_as_long / base_len, fd);
	ft_putchar_fd(base[n_as_long % base_len], fd);
}

int	ft_preparsing(char const *fmt)
{
	size_t	i;

	i = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
			if (!ft_char_in_s(fmt[i + 1], "cspdiuxX%"))
				return (0);
		i++;
	}
	return (1);
}

size_t	ft_count_if_not_flag(char const *fmt)
{
	size_t	i;

	i = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
			i += 2;
		else
			i++;
	}
	return (i);
}

size_t	ft_count_flags(char const *fmt)
{
	size_t	f;

	f = 0;
	while (*fmt)
	{
		if (*fmt == '%')
			f++;
		fmt++;
	}
	return (f);
}

t_flag_var	*ft_parse_flags(char const *fmt, va_list args, size_t flag_cnt)
{
	t_flag_var	*arr;
	size_t		i;

	arr = ft_calloc(flag_cnt + 1, sizeof(t_flag_var));
	if (!arr)
		return (0);
	i = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			if (*(fmt + 1) == 'c')
			{
				arr[i].flag = F_CHR;
				arr[i].int_ = va_arg(args, int);
			}
			else if (*(fmt + 1) == 's')
			{
				arr[i].flag = F_STR;
				arr[i].str_ = va_arg(args, char *);
			}
			else if (*(fmt + 1) == 'p')
			{
				arr[i].flag = F_PTR;
				arr[i].ulong_ = va_arg(args, unsigned long);
			}
			else if (*(fmt + 1) == 'u')
			{
				arr[i].flag = F_UIN;
				arr[i].uint_ = va_arg(args, unsigned int);
			}
			else if (*(fmt + 1) == 'i' || *(fmt + 1) == 'd')
			{
				arr[i].flag = F_INT;
				arr[i].int_ = va_arg(args, int);
			}
			else if (*(fmt + 1) == 'x')
			{
				arr[i].flag = F_HEX;
				arr[i].uint_ = va_arg(args, unsigned);
			}
			else if (*(fmt + 1) == 'X')
			{
				arr[i].flag = F_HEXU;
				arr[i].uint_ = va_arg(args, unsigned);
			}
			else if (*(fmt + 1) == '%')
			{
				arr[i].flag = F_ESC;
				arr[i].int_ = '%';
			}
			i++;
		}
		fmt++;
	}
	return (arr);
}

t_string_stats	ft_init_stats(char const *fmt, va_list args)
{
	t_string_stats	stats;

	stats.const_sz = ft_count_if_not_flag(fmt);
	stats.total_sz = ft_strlen(fmt);
	stats.flag_cnt = ft_count_flags(fmt);
	stats.flag_var_arr = ft_parse_flags(fmt, args, stats.flag_cnt);
	return (stats);
}

int	ft_printf(char const *fmt, ...)
{
	va_list			args;
	t_string_stats	stats;

	va_start(args, fmt);
	if (ft_preparsing(fmt) == 0)
		return (0);
	stats = ft_init_stats(fmt, args);
	return (0);
}

int	main(void)
{
	char const	*w = "eiugwlfvl";

	// ft_printf("FT_PRINTF >>> %c le char ou quoi et %x l'entier GROS POINTEUR %p GROS STRING %s %%\n", 'q', -(0x465), w, w);
	printf("   PRINTF >>> %c le char ou quoi et %x l'entier GROS POINTEUR %p GROS STRING %s %%\n", 'q', -(0x465), w, w);
	return (0);
}
