/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 20:01:13 by tblochet          #+#    #+#             */
/*   Updated: 2024/11/27 16:30:28 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *fmt, ...)
{
	va_list	args;
	t_flags	flags;
	int		len;

	if (!fmt)
		return (-1);
	va_start(args, fmt);
	flags.n = ft_count_flags(fmt);
	if (flags.n < 0)
		return (-1);
	flags.val = ft_parse_flags(fmt, args, flags.n);
	len = ft_display_formatted(fmt, &flags);
	free(flags.val);
	return (len);
}

/* int main(void)
{
	#include <stdio.h>
	ft_printf("<--->\n START >");
	int d1 = ft_printf("%t");
	printf("< STOP \n<--->\n START >");
	int d2 = printf("%t");
	printf("< STOP \n<--->\n");
	printf("1: %d / 2: %d\n", d1, d2);
	return (0);
} */
