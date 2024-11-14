/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:29:48 by tblochet          #+#    #+#             */
/*   Updated: 2024/11/14 17:02:57 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_char_in_s(char c, char const *s)
{
	while (*s)
		if (c == *s++)
			return (1);
	return (0);
}

void	ft_strrev(char *str)
{
	int				i;
	int				j;
	char			a;
	size_t const	len = ft_strlen((const char *)str);

	i = 0;
	j = len - 1;
	while (i < j)
	{
		a = str[i];
		str[i] = str[j];
		str[j] = a;
		i++;
		j--;
	}
}

char	*ft_itoa_base(unsigned long n, char const *base)
{
	int			i;
	int			digit;
	char		*str;

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

char	*ft_strjoin_and_free(char const *s1, char *s2)
{
	char	*ret;

	ret = ft_strjoin(s1, s2);
	free(s2);
	return (ret);
}