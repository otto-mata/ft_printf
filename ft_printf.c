/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 20:01:13 by tblochet          #+#    #+#             */
/*   Updated: 2024/11/19 17:13:13 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_printf(char const *fmt, ...)
{
	va_list			args;
	t_string_stats	stats;
	int				len;

	va_start(args, fmt);
	stats.flag_cnt = ft_count_flags(fmt);
	if (stats.flag_cnt < 0)
		return (0);
	stats.flgs_ctnt = ft_parse_flags(fmt, args, stats.flag_cnt);
	len = ft_display_fmtd_str(fmt, &stats);
	free(stats.flgs_ctnt);
	return (len);
}

/* int main()
{
	ft_printf("<--->\n START >");
	int d1 = ft_printf("");
	printf("< STOP \n<--->\n START >");
	int d2 = printf("%-+10d",-50);
	printf("< STOP \n<--->\n");
	printf("1: %d / 2: %d\n", d1, d2);
	return 0;
} */
