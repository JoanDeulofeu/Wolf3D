/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgehin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:44:31 by jgehin            #+#    #+#             */
/*   Updated: 2018/11/21 10:10:07 by jgehin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	int		ct;
	size_t	ctbis;

	ct = 0;
	ctbis = 0;
	while (dest[ct] != '\0')
		ct++;
	while (src[ctbis] != '\0' && (ctbis < n))
		dest[ct++] = src[ctbis++];
	dest[ct] = '\0';
	return (dest);
}
