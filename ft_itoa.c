/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:01:51 by tblochet          #+#    #+#             */
/*   Updated: 2024/12/11 20:35:08 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	ft_intlen(int32_t n)
{
	int	sz;

	if (n == INT32_MIN)
		return (10);
	if (n == 0)
		return (1);
	sz = 0;
	n = ft_abs(n);
	while (n)
	{
		sz++;
		n /= 10;
	}
	return (sz);
}

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

char	*ft_itoa(int n)
{
	int const	sign = (n < 0);
	int const	nlen = ft_intlen(n);
	int			i;
	int			digit;
	char		*str;

	if (n == 0)
		return (ft_strdup("0"));
	str = ft_calloc(nlen + sign + 1, sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (i < nlen)
	{
		digit = n % 10;
		str[i++] = '0' + ft_abs(digit);
		n /= 10;
	}
	if (sign)
		str[i] = '-';
	ft_strrev(str);
	return (str);
}
