/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:26:51 by tblochet          #+#    #+#             */
/*   Updated: 2024/11/22 12:10:24 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libs/libft/libft.h"
# include <limits.h>
# include <stdarg.h>

typedef struct s_string_stats
{
	size_t	flag_cnt;
	char	**flgs_ctnt;
}			t_string_stats;

int			ft_printf(char const *fmt, ...);
int			ft_display_formatted(char const *fmt, t_string_stats *stats);
char		**ft_parse_flags(char const *fmt, va_list args, size_t flag_cnt);
int			ft_count_flags(char const *fmt);
int			ft_char_in_s(char c, char const *s);
void		ft_strrev(char *str);
char		*ft_itoa_base(unsigned long n, char const *base);
char		*ft_itoa_base_int(unsigned int n, char const *base);
char		*ft_specialjoin(char const *s1, char *s2);
void		ft_parse_arg(char flag, va_list args, char **arr);

#endif