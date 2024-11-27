/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specialjoin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:29:48 by tblochet          #+#    #+#             */
/*   Updated: 2024/11/26 14:31:45 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_specialjoin(char const *s1, char *s2)
{
	char	*ret;

	ret = ft_strjoin(s1, s2);
	if (ft_strncmp(ret, "0x0", ft_strlen(ret)) == 0)
	{
		free(ret);
		ret = ft_strdup("(nil)");
	}
	free(s2);
	return (ret);
}
