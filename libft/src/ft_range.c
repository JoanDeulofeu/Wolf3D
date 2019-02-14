/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgehin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:45:54 by jgehin            #+#    #+#             */
/*   Updated: 2018/11/07 14:18:43 by jgehin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int		*res;
	int		i;

	i = 0;
	if (min >= max)
		return (0);
	if (!(res = (int*)malloc(sizeof(*res) * ((max - min) + 1))))
		return (0);
	min--;
	while (++min < max)
		res[i++] = min;
	return (res);
}
