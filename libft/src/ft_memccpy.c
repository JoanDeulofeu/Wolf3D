/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgehin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:22:29 by jgehin            #+#    #+#             */
/*   Updated: 2018/11/13 15:14:31 by jgehin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*t1;
	const unsigned char	*t2;
	unsigned char		t3;
	size_t				i;

	t1 = dest;
	t2 = src;
	t3 = c;
	i = -1;
	while (++i != n)
	{
		if (t3 == *(t2))
		{
			*(t1++) = *(t2++);
			return (t1);
		}
		*(t1++) = *(t2++);
	}
	return (NULL);
}
