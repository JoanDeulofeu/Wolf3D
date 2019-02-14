/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgehin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 09:44:25 by jgehin            #+#    #+#             */
/*   Updated: 2018/11/16 19:42:20 by jgehin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <string.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tab;
	int		len;
	int		len2;
	int		i;
	int		u;

	u = 0;
	i = 0;
	if (!s1 || !s2)
		return (0);
	len = (s1[i] != '\0') ? ft_strlen(s1) : 0;
	if (s2[i] != '\0')
		len2 = ft_strlen(s2);
	else
		len2 = 0;
	if (!(tab = (char*)malloc(sizeof(*tab) * (len + len2 + 1))))
		return (NULL);
	while (len-- > 0)
		tab[i++] = s1[u++];
	u = 0;
	while (len2-- > 0)
		tab[i++] = s2[u++];
	tab[i++] = '\0';
	return (tab);
}
