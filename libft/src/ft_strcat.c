/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgehin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:36:23 by jgehin            #+#    #+#             */
/*   Updated: 2018/11/09 17:37:43 by jgehin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, const char *src)
{
	int ct;
	int ctbis;

	ct = 0;
	ctbis = 0;
	while (dest[ct] != '\0')
		ct++;
	while (src[ctbis] != '\0')
		dest[ct++] = src[ctbis++];
	dest[ct] = '\0';
	return (dest);
}
