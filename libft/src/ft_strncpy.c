/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgehin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:12:14 by jgehin            #+#    #+#             */
/*   Updated: 2018/11/21 10:10:50 by jgehin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	int ct;

	ct = -1;
	while (src[++ct] != '\0' && ct < (int)n)
		dest[ct] = src[ct];
	while (ct < (int)n)
		dest[ct++] = '\0';
	return (dest);
}
