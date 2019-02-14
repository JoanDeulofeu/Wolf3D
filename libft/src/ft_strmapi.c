/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgehin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 18:27:29 by jgehin            #+#    #+#             */
/*   Updated: 2018/11/16 19:31:44 by jgehin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int				len;
	char			*tab;
	int				i;
	unsigned int	u;

	i = 0;
	u = 0;
	if (!s || !f)
		return (0);
	len = ft_strlen(s);
	if (!(tab = (char*)malloc(sizeof(*tab) * len + 1)))
		return (NULL);
	while (s[i])
	{
		tab[i] = (*f)(u++, s[i]);
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
