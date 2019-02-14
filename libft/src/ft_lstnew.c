/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgehin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 18:58:34 by jgehin            #+#    #+#             */
/*   Updated: 2018/11/19 11:30:15 by jgehin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <string.h>

static void	*ft_cpy(void const *content, size_t content_size)
{
	unsigned char	*p;
	unsigned char	*p2;
	void			*cnt;

	if (!(cnt = ft_memalloc(content_size)))
		return (NULL);
	p = (unsigned char*)content;
	p2 = (unsigned char*)cnt;
	while (*p)
	{
		*(p2++) = *(p++);
	}
	return (cnt);
}

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	if (!(new = (t_list*)malloc(sizeof(*new))))
		return (0);
	new->content = content ? ft_cpy(content, content_size) : NULL;
	new->content_size = content ? content_size : 0;
	new->next = NULL;
	return (new);
}
