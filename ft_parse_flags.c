/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:10:46 by tblochet          #+#    #+#             */
/*   Updated: 2024/11/19 17:11:02 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "includes/ft_printf.h"

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