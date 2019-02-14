/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgehin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 13:55:58 by jgehin            #+#    #+#             */
/*   Updated: 2018/11/16 14:56:59 by jgehin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

static void		ftcopy(char *s, int len, int n)
{
	int i;

	while (--len >= 0)
	{
		i = (n % 10) < 0 ? -(n % 10) : (n % 10);
		s[len] = i + 48;
		n /= 10;
	}
}

char			*ft_itoa(int n)
{
	int		div;
	int		len;
	int		i;
	char	*s;

	i = 0;
	len = 0;
	div = n;
	while (div != 0)
	{
		div /= 10;
		len++;
	}
	len = n < 0 ? len + 1 : len;
	len = n == 0 ? 1 : len;
	if (!(s = (char*)malloc(sizeof(*s) * (len + 1))))
		return (NULL);
	s[len] = '\0';
	ftcopy(s, len, n);
	if (n < 0)
		s[0] = '-';
	return (s);
}
