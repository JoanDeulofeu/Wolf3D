/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 11:11:09 by fmerding          #+#    #+#             */
/*   Updated: 2019/03/18 14:29:24 by jgehin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

char	*ft_check2(t_s *s, char *line)
{
	int		width;
	int		i;

	width = 0;
	i = -1;
	s->high++;
	while (line[++i] != '\0')
	{
		if (line[i] != ',' && line[i] != ' ' && line[i] != '\n' &&
			(line[i] < 48 && line[i] > 57))
			ft_usage(2);
		if (line[i] == ',')
			width += 1;
	}
	if (s->high == 1)
		s->width = width / 4;
	if ((width / 4) != s->width)
		ft_usage(2);
	ft_memdel((void **)&line);
	return (line);
}

void	ft_check(t_s *s, char *av)
{
	int		fd;
	char	*line;

	fd = open(av, O_RDONLY);
	while (get_next_line(fd, &line))
		line = ft_check2(s, line);
	ft_memdel((void **)&line);
	close(fd);
	if (s->high != s->width || s->high > 10)
		ft_usage(2);
}

void	ft_check_post_2(t_s *s, int x, int y)
{
	if (s->map[x][y]->envi != 1 && s->map[x][y]->envi != 1000 &&
		s->map[x][y]->envi != 1001 && s->map[x][y]->envi != 1100)
		ft_usage(2);
	if (s->map[x][y]->envi_sz < 1 || s->map[x][y]->envi_sz > 5)
		ft_usage(2);
	if (s->map[x][y]->roof < 1 || s->map[x][y]->roof > 999)
		ft_usage(2);
	if (s->map[x][y]->roof_sz < 1 || s->map[x][y]->roof_sz > 5)
		ft_usage(2);
	if (s->map[x][y]->item < 1 || s->map[x][y]->item > 99)
		ft_usage(2);
	if ((x == 0 || x == s->high - 1) && s->map[x][y]->envi < 1002)
		ft_usage(4);
	if ((y == 0 || y == s->width - 1) && s->map[x][y]->envi < 1002)
		ft_usage(4);
	if ((s->map[x][y]->item > 1 && s->map[x][y]->item < 6) &&
	s->map[x][y]->envi > 999)
		ft_usage(3);
	if (s->map[x][y]->envi == 1000 && (s->map[x + 1][y]->envi < 1002 ||
	s->map[x - 1][y]->envi < 1002))
		ft_usage(2);
	if (s->map[x][y]->envi == 1001 && (s->map[x][y + 1]->envi < 1002 ||
	s->map[x][y - 1]->envi < 1002))
		ft_usage(2);
}

void	ft_check_post_pars(t_s *s)
{
	int x;
	int y;
	int player;

	player = 0;
	x = -1;
	y = -1;
	while (++x < s->high)
	{
		while (++y < s->width)
		{
			ft_check_post_2(s, x, y);
			if (s->map[x][y]->item > 1 && s->map[x][y]->item < 6)
				player++;
		}
		y = 0;
	}
	if (player != 1)
		ft_usage(3);
}
