/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgehin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 09:30:27 by jgehin            #+#    #+#             */
/*   Updated: 2018/11/16 19:43:32 by jgehin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*tab;
	int		i;

	i = 0;
	if (!s)
		return (0);
	if (!(tab = (char*)malloc(sizeof(*tab) * len + 1)))
		return (NULL);
	while (len-- > 0)
		tab[i++] = s[start++];
	tab[i] = '\0';
	return (tab);
}
