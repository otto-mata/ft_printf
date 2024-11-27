/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_formatted.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:11:44 by tblochet          #+#    #+#             */
/*   Updated: 2024/11/26 14:32:34 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_display_formatted(char const *fmt, t_flags *f)
{
	size_t	i;
	size_t	j;
	int		len;

	i = 0;
	j = 0;
	len = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			if (fmt[i + 1] == 'c')
				(ft_putchar_fd(*f->val[j], 1), len++);
			else
				(ft_putstr_fd(f->val[j], 1), len += ft_strlen(f->val[j]));
			free(f->val[j++]);
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
