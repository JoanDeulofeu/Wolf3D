/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgehin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:39:00 by jgehin            #+#    #+#             */
/*   Updated: 2018/11/19 12:12:18 by jgehin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*t1;
	unsigned char		t2;
	size_t				i;

	t1 = s;
	t2 = c;
	i = 0;
	while (++i < n)
	{
		if (t2 == *t1)
			return ((void*)(t1));
		if (t2 == *(++t1))
			return ((void*)(t1));
	}
	return (NULL);
}
