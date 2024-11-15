/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 20:01:13 by tblochet          #+#    #+#             */
/*   Updated: 2024/11/15 15:33:39 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"


typedef enum e_format_justif{
	LEFT,
	RIGHT
}		t_format_justif;

static int	ft_uintlen(uint32_t n)
{
	int	sz;

	if (n == 0)
		return (1);
	sz = 0;
	while (n > 0)
	{
		sz++;
		n /= 10;
	}
	return (sz);
}

char	*ft_itoa_unsigned(uint32_t n)
{
	int const	nlen = ft_uintlen(n);
	int			i;
	int			digit;
	char		*str;

	if (n == 0)
		return (ft_strdup("0"));
	str = ft_calloc(nlen + 1, sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (i < nlen)
	{
		digit = n % 10;
		str[i++] = '0' + digit;
		n /= 10;
	}
	ft_strrev(str);
	return (str);
}

int	ft_flag_count(char const *fmt)
{
	size_t	i;
	int		flgs;

	flgs = 0;
	i = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			if (!ft_char_in_s(fmt[i + 1], "cspdiuxX%.- "))
			{
				flgs = -1;
				break ;
			}
			flgs++;
			i++;
		}
		i++;
	}
	return (flgs);
}

char	*ft_parse_string(char *s)
{
	if (!s)
		return (ft_strdup("(null)"));
	return (ft_strdup(s));
}

void	ft_parse_arg(char flag, va_list args, char **arr)
{
	char		*cast;
	char const	*hex = "0123456789abcdef";

	if (flag == 'c')
	{
		cast = ft_calloc(1, 1);
		*cast = va_arg(args, int) % 256;
		*arr = cast;
	}
	else if (flag == 's')
		*arr = ft_parse_string(va_arg(args, char *));
	else if (flag == 'u')
		*arr = ft_itoa_unsigned(va_arg(args, uint32_t));
	else if (flag == 'i' || flag == 'd')
		*arr = ft_itoa(va_arg(args, int));
	else if (flag == 'x')
		*arr = ft_itoa_base_int(va_arg(args, uint32_t), hex);
	else if (flag == 'p')
		*arr = ft_specialjoin("0x", ft_itoa_base(va_arg(args, uint64_t), hex));
	else if (flag == 'X')
		*arr = ft_itoa_base_int(va_arg(args, uint32_t), "0123456789ABCDEF");
	else if (flag == '%')
		*arr = ft_strdup("%");
}

char	**ft_parse_flags(char const *fmt, va_list args, size_t flag_cnt)
{
	char	**arr;
	size_t	i;

	arr = ft_calloc(flag_cnt + 1, sizeof(char *));
	if (!arr)
		return (0);
	i = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			ft_parse_arg(*(fmt + 1), args, &arr[i]);
			i++;
			fmt++;
		}
		fmt++;
	}
	return (arr);
}

int	ft_display_fmtd_str(char const *fmt, t_string_stats *stats)
{
	size_t			i;
	size_t			j;
	int				len;

	i = 0;
	j = 0;
	len = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			if (fmt[i + 1] == 'c')
			{
				ft_putchar_fd(*stats->flgs_ctnt[j], 1);
				len++;
			}
			else
			{
				ft_putstr_fd(stats->flgs_ctnt[j], 1);
				len += ft_strlen(stats->flgs_ctnt[j]);
			}
			free(stats->flgs_ctnt[j++]);
			i += 2;
			continue ;
		}
		else
			ft_putchar_fd(fmt[i], 1);
		i++;
		len++;
	}
	return (len);
}

int	ft_printf(char const *fmt, ...)
{
	va_list			args;
	t_string_stats	stats;
	int				len;

	va_start(args, fmt);
	stats.flag_cnt = ft_flag_count(fmt);
	if (stats.flag_cnt < 0)
		return (0);
	stats.flgs_ctnt = ft_parse_flags(fmt, args, stats.flag_cnt);
	len = ft_display_fmtd_str(fmt, &stats);
	free(stats.flgs_ctnt);
	return (len);
}

char	*format_npad(unsigned long n, char c)
{
	char	*s;

	s = ft_calloc(n + 1, sizeof(char));
	if (!s)
		return (0);
	s = ft_memset(s, c, n);
	return (s);
}

char	*printf_left_justify(uint64_t n,
	char *to_justify, char c, t_format_justif dir)
{
	char	*padding;
	char	*out;

	if (n > INT32_MAX)
		return (0);
	padding = format_npad(n - ft_strlen(to_justify), c);
	if (dir == LEFT)
		out = ft_strjoin(to_justify, padding);
	else
		out = ft_strjoin(padding, to_justify);
	free(padding);
	free(to_justify);
	return (out);
}

int main()
{
	ft_printf("<--->\n START >");
	int d1 = ft_printf("");
	printf("< STOP \n<--->\n START >");
	int d2 = printf("%-+10d",-50);
	printf("< STOP \n<--->\n");
	printf("1: %d / 2: %d\n", d1, d2);
	return 0;
}
