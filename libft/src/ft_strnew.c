/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgehin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 16:57:32 by jgehin            #+#    #+#             */
/*   Updated: 2018/11/13 15:02:09 by jgehin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_strnew(size_t size)
{
	char *tab;
	char *res;

	if (!(tab = (char*)malloc(sizeof(*tab) * ++size)))
		return (NULL);
	res = tab;
	while (size-- > 0)
		*(tab++) = '\0';
	return (res);
}
