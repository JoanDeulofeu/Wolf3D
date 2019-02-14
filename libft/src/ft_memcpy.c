/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgehin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:24:44 by jgehin            #+#    #+#             */
/*   Updated: 2018/11/10 12:29:57 by jgehin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*t1;
	const unsigned char	*t2;

	t1 = dest;
	t2 = src;
	while (n-- > 0)
		*(t1++) = *(t2++);
	return (dest);
}
