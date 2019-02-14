/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgehin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 16:38:33 by jgehin            #+#    #+#             */
/*   Updated: 2018/11/15 18:46:20 by jgehin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void *tab;
	char *res;

	if (!(tab = (char*)malloc(size)))
		return (NULL);
	res = tab;
	while (size-- > 0)
		*(res++) = 0;
	return (tab);
}
