/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:22:40 by tblochet          #+#    #+#             */
/*   Updated: 2024/12/11 20:27:32 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hexlen(unsigned long n)
{
	int	i;

	i = 1;
	while (n / 16)
	{
		i++;
		n /= 16;
	}
	return (i);
}

char	*ft_ltoh(unsigned long n, bool upper)
{
	int		i;
	char	*hexd;
	char	*base;

	i = hexlen(n) - 1;
	hexd = ft_calloc(hexlen(n) + 1, sizeof(char));
	if (!hexd)
		return (0);
	if (upper)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	while (i > -1)
	{
		hexd[i] = base[n % 16];
		i--;
		n /= 16;
	}
	return (hexd);
}