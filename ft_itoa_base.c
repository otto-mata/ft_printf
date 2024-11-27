/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:22:40 by tblochet          #+#    #+#             */
/*   Updated: 2024/11/26 14:26:06 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_base(unsigned long n, char const *base)
{
	int		i;
	int		digit;
	char	*str;

	if (n == 0)
		return (ft_strdup("0"));
	str = ft_calloc(64, sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (n > 0)
	{
		digit = n % ft_strlen(base);
		str[i++] = base[digit];
		n /= ft_strlen(base);
	}
	ft_strrev(str);
	return (str);
}
