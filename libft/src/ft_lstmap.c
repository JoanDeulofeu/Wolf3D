/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgehin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 16:20:47 by jgehin            #+#    #+#             */
/*   Updated: 2018/11/19 11:34:16 by jgehin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res;
	t_list	*new;
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	new = f(lst);
	res = new;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		new->next = tmp;
		tmp->next = NULL;
		new = tmp;
		lst = lst->next;
	}
	return (res);
}
