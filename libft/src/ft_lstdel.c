/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgehin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 10:28:05 by jgehin            #+#    #+#             */
/*   Updated: 2018/11/16 12:57:48 by jgehin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *alst;
	while (tmp)
	{
		tmp2 = tmp;
		del((tmp)->content, (tmp)->content_size);
		free(tmp);
		tmp = tmp2->next;
	}
	*alst = NULL;
}
