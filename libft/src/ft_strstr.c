/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgehin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 20:05:05 by jgehin            #+#    #+#             */
/*   Updated: 2018/11/09 20:05:25 by jgehin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *str, const char *to_find)
{
	int	ct;
	int u;

	u = 0;
	ct = 0;
	if (to_find[0] == '\0')
		return ((char *)str);
	while (str[u] != '\0')
	{
		while (str[ct] == to_find[ct])
		{
			ct++;
			if (to_find[ct] == '\0')
				return ((char *)str);
		}
		ct = 0;
		str++;
	}
	return (0);
}
