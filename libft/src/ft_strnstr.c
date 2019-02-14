/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgehin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 11:00:57 by jgehin            #+#    #+#             */
/*   Updated: 2018/11/14 14:42:53 by jgehin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	int		ct;
	size_t	i;
	size_t	y;

	i = len + 1;
	ct = 0;
	if (to_find[0] == '\0')
		return ((char *)str);
	while (str[0] != '\0' && i-- > 0)
	{
		y = i;
		while (str[ct] == to_find[ct] && y-- > 0)
		{
			ct++;
			if (to_find[ct] == '\0')
				return ((char *)str);
		}
		ct = 0;
		str++;
	}
	return (0);
}
