/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgehin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 11:21:02 by jgehin            #+#    #+#             */
/*   Updated: 2018/11/16 19:46:34 by jgehin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	char	*tab;
	int		i;

	if (!s)
		return (0);
	while (*(s) == ' ' || *(s) == '\n' || *(s) == '\t')
		(s++);
	i = ft_strlen(s);
	if (i > 0)
	{
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t' || s[i] == '\0')
			i--;
		i++;
	}
	if (!(tab = (char*)malloc(sizeof(*tab) * i + 1)))
		return (NULL);
	ft_strncpy(tab, (char*)s, i);
	tab[i] = '\0';
	return (tab);
}
