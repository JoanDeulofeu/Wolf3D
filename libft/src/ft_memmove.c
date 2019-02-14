/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgehin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:49:58 by jgehin            #+#    #+#             */
/*   Updated: 2018/11/14 16:04:30 by jgehin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*t1;
	const unsigned char	*t2;
	int					i;

	t1 = dest;
	t2 = src;
	i = 0;
	if (t1 > t2)
	{
		while (i <= (int)--n)
			t1[n] = t2[n];
	}
	if (t1 < t2)
	{
		i--;
		while (++i < (int)n)
			t1[i] = t2[i];
	}
	return (dest);
}
