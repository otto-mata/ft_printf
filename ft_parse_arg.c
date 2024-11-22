/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:09:15 by tblochet          #+#    #+#             */
/*   Updated: 2024/11/19 17:11:00 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

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

static char	*ft_itoa_unsigned(uint32_t n)
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

static char	*ft_parse_string(char *s)
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