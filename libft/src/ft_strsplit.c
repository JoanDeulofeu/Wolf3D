/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgehin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:09:02 by jgehin            #+#    #+#             */
/*   Updated: 2018/11/16 19:44:56 by jgehin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

static int	nbmot(char const *str, char c)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			nb++;
		i++;
	}
	return (nb);
}

static int	lgmot(const char *str, char c)
{
	int i;

	i = 0;
	while (*str == c)
		str++;
	while (str[i] != c && str[i] != '\0')
		i++;
	return (i);
}

const char	*ftcopy(const char *str, char *tub, char c)
{
	int i;

	i = -1;
	while (*str == c)
		str++;
	while (*str != c && *str != '\0')
		tub[++i] = *(str++);
	tub[++i] = '\0';
	return (str);
}

char		**ft_strsplit(char const *str, char c)
{
	int		u;
	char	**tab;
	int		nb;

	u = -1;
	if (!str || !c)
		return (0);
	nb = nbmot(str, c);
	if (!(tab = (char**)malloc(sizeof(*tab) * (nb + 1))))
		return (NULL);
	while (++u < nb)
	{
		if (!(tab[u] = (char*)malloc(sizeof(**tab) * lgmot(str, c) + 1)))
			return (0);
		str = ftcopy(str, tab[u], c);
	}
	tab[u] = 0;
	return (tab);
}
