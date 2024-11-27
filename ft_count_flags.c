/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:12:42 by tblochet          #+#    #+#             */
/*   Updated: 2024/11/26 15:31:05 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_flags(char const *fmt)
{
	size_t	i;
	int		flgs;

	flgs = 0;
	i = 0;
	while (fmt[i] && flgs >= 0)
	{
		if (fmt[i] == '%')
		{
			if (!ft_char_in_s(fmt[i + 1], "cspdiuxX%"))
				flgs = -1;
			else
				flgs++;
			i++;
		}
		i++;
	}
	return (flgs);
}
