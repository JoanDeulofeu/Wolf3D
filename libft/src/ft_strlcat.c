/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgehin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 18:33:56 by jgehin            #+#    #+#             */
/*   Updated: 2018/11/21 10:09:47 by jgehin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t i;
	size_t u;
	size_t res;

	i = 0;
	u = 0;
	res = (ft_strlen(dest) + ft_strlen(src));
	while (dest[i] != '\0')
		i++;
	if (n <= i)
		return (ft_strlen(src) + n);
	while (src[u] != '\0' && i < (n - 1))
		dest[i++] = src[u++];
	dest[i] = '\0';
	return (res);
}
