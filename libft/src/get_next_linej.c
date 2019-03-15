/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgehin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 10:49:31 by jgehin            #+#    #+#             */
/*   Updated: 2018/12/10 11:18:31 by jgehin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

t_glist		*ft_newglist(int fd)
{
	t_glist		*list;
	int			res;

	if (!(list = (t_glist *)malloc(sizeof(t_glist))))
		return (NULL);
	if (!(list->tmp = ft_strnew(BUFF_SIZE + 1)))
		return (NULL);
	res = read(fd, list->tmp, BUFF_SIZE);
	if (res == -1)
		return (NULL);
	list->fd = fd;
	list->next = NULL;
	return (list);
}

t_glist		*ft_goodlist(t_glist *flist, int fd)
{
	t_glist	*list;

	while (flist)
	{
		if (flist->fd == fd)
			return (flist);
		if (!(flist->next))
			break ;
		flist = flist->next;
	}
	if ((list = ft_newglist(fd)) == NULL)
		return (NULL);
	flist->next = list;
	return (list);
}

void		ft_move_line(t_glist *list, char **line, char *bsn)
{
	char	*pren;
	char	*postn;
	char	*tmp;

	pren = ft_strsub(list->tmp, 0, bsn - list->tmp);
	postn = ft_strsub(list->tmp, (bsn - list->tmp) + 1, ft_strlen(list->tmp));
	tmp = *line;
	*line = ft_strjoin(*line, pren);
	ft_memdel((void **)&(list->tmp));
	list->tmp = postn;
	ft_memdel((void **)&tmp);
	ft_memdel((void **)&pren);
}

int			ft_read(int fd, t_glist *list, char **line)
{
	char	*bsn;
	int		res;
	int		len;

	res = 1;
	while (res > 0)
	{
		if ((bsn = ft_strchr(list->tmp, '\n')))
		{
			ft_move_line(list, line, bsn);
			return (1);
		}
		*line = ft_strjoin(*line, list->tmp);
		len = ft_strlen(list->tmp);
		ft_memdel((void **)&(list->tmp));
		if (!(list->tmp = ft_strnew(BUFF_SIZE + 1)))
			return (-1);
		res = read(fd, list->tmp, BUFF_SIZE);
		if (!len && !res)
			return (0);
	}
	return (1);
}

int			get_next_line(int const fd, char **line)
{
	int					res;
	static t_glist		*flist;
	t_glist				*list;

	if (!line || fd < 0 || BUFF_SIZE < 1)
		return (-1);
	if (!flist)
	{
		if (!(flist = ft_newglist(fd)))
			return (-1);
	}
	*line = ft_strdup("");
	if (!(list = ft_goodlist(flist, fd)))
		return (-1);
	res = ft_read(fd, list, line);
	if (res > 0)
		return (1);
	if (res == 0)
		return (0);
	return (-1);
}
