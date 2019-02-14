/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgehin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 14:02:46 by jgehin            #+#    #+#             */
/*   Updated: 2018/11/21 10:09:01 by jgehin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <string.h>

char	*ft_strdup(const char *src)
{
	char	*res;
	int		i;

	i = -1;
	if (!(res = (char*)malloc(sizeof(*res) * (ft_strlen(src) + 1))))
		return (0);
	while (src[++i] != '\0')
		res[i] = src[i];
	res[i] = '\0';
	return (res);
}
