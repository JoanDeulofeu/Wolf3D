/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgehin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 13:53:43 by jgehin            #+#    #+#             */
/*   Updated: 2018/11/19 14:10:34 by jgehin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_islower(int str)
{
	if (str)
	{
		if (str < 97 || str > 122)
			return (0);
		return (1);
	}
	return (0);
}
