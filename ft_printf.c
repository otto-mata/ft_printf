/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 20:01:13 by tblochet          #+#    #+#             */
/*   Updated: 2024/11/14 16:56:20 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

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
			if (!ft_char_in_s(fmt[i + 1], "cspdiuxX%"))
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

void	ft_parse_arg(char flag, va_list args, char **arr)
{
	char	cast;

	if (flag == 'c')
	{
		cast = va_arg(args, int) % 256;
		*arr = ft_strdup(&cast);
	}
	else if (flag == 's')
		*arr = ft_strdup(va_arg(args, char *));
	else if (flag == 'u')
		*arr = ft_itoa(va_arg(args, unsigned int));
	else if (flag == 'i' || flag == 'd')
		*arr = ft_itoa(va_arg(args, int));
	else if (flag == 'x')
		*arr = ft_itoa_base(
				va_arg(args, unsigned long), "0123456789abcdef");
	else if (flag == 'p')
		*arr = ft_strjoin_and_free("0x", ft_itoa_base(
					va_arg(args, unsigned long),
					"0123456789abcdef"));
	else if (flag == 'X')
		*arr = ft_itoa_base(va_arg(args, unsigned long), "0123456789ABCDEF");
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
			ft_putstr_fd(stats->flgs_ctnt[j], 1);
			len += ft_strlen(stats->flgs_ctnt[j]);
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
