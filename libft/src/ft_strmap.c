/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgehin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 17:44:48 by jgehin            #+#    #+#             */
/*   Updated: 2018/11/16 19:39:35 by jgehin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		len;
	char	*tab;
	int		i;

	i = 0;
	if (!s || !f)
		return (0);
	len = ft_strlen(s);
	if (!(tab = (char*)malloc(sizeof(*tab) * len + 1)))
		return (NULL);
	while (*s)
		tab[i++] = (*f)(*s++);
	tab[i] = '\0';
	return (tab);
}
