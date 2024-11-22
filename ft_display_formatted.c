/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_formatted.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:11:44 by tblochet          #+#    #+#             */
/*   Updated: 2024/11/22 12:09:37 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_display_formatted(char const *fmt, t_string_stats *stats)
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
