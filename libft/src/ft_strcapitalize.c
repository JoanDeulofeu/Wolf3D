/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgehin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 13:43:00 by jgehin            #+#    #+#             */
/*   Updated: 2018/11/19 13:43:39 by jgehin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int ct;

	ct = 0;
	while (str[ct] != '\0')
	{
		if (str[ct] >= 'A' && str[ct] <= 'Z')
			str[ct] = str[ct] + 32;
		++ct;
	}
	ct = 1;
	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] = str[0] - 32;
	while (str[ct] != '\0')
	{
		if (((str[ct - 1] < '0' || str[ct - 1] > '9') && (str[ct - 1] < 'a'
			|| str[ct - 1] > 'z') && (str[ct - 1] < 'A' || str[ct - 1] > 'Z'))
			&& (str[ct] >= 'a' && str[ct] <= 'z'))
			str[ct] = str[ct] - 32;
		ct++;
	}
	return (str);
}
