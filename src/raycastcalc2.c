/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycastcalc2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 16:01:43 by fmerding          #+#    #+#             */
/*   Updated: 2019/03/15 16:17:16 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_dir_raycasting1x(t_s *s, float angle, int x, int y)
{
	while (1)
	{
		if (s->map[x][y]->envi == 1001 && (s->pos->moovex - SPACE / 2) < x
		* SPACE)
		{
			s->ray->intx = x * SPACE + SPACE / 2;
			s->pos->doorx = 1;
		}
		else
		{
			x++;
			s->ray->intx = x * SPACE;
		}
		s->ray->diffx = s->ray->intx - s->pos->moovex;
		s->ray->diffy = tan(angle) * s->ray->diffx;
		s->ray->inty = s->pos->moovey - s->ray->diffy;
		y = s->ray->inty / SPACE;
		s->ray->save1 = sqrtf(powf(s->ray->diffx, 2) + powf(s->ray->diffy, 2));
		if (x >= s->width || y >= s->high || y < 0 || x < 0)
			break ;
		if (s->map[x][y]->envi > 1001)
			break ;
		if (s->pos->doorx == 1)
			break ;
	}
}

void	ft_dir_raycasting1y(t_s *s, float angle2, int x, int y)
{
	while (1)
	{
		if (s->map[x][y]->envi == 1000 && (s->pos->moovey - SPACE / 2) > y
		* SPACE)
		{
			s->ray->inty2 = y * SPACE + SPACE / 2;
			s->pos->doory = 1;
		}
		else
			s->ray->inty2 = y * SPACE;
		s->ray->diffy = s->pos->moovey - s->ray->inty2;
		s->ray->diffx = tan(angle2) * s->ray->diffy;
		s->ray->intx2 = s->pos->moovex + s->ray->diffx;
		x = s->ray->intx2 / SPACE;
		s->ray->save2 = sqrtf(powf(s->ray->diffx, 2) + powf(s->ray->diffy, 2));
		if (x >= s->width || y >= s->high || y < 0 || x < 0)
			break ;
		if (s->map[x][y - 1]->envi > 1001)
			break ;
		y--;
		if (s->pos->doory == 1)
			break ;
	}
}

void	ft_dir_raycasting2x(t_s *s, float angle, int x, int y)
{
	while (1)
	{
		if (s->map[x][y]->envi == 1001 && (s->pos->moovex - SPACE / 2) < x
		* SPACE)
		{
			s->ray->intx = x * SPACE + SPACE / 2;
			s->pos->doorx = 1;
		}
		else
		{
			x++;
			s->ray->intx = x * SPACE;
		}
		s->ray->diffx = s->ray->intx - s->pos->moovex;
		s->ray->diffy = tan(angle) * s->ray->diffx;
		s->ray->inty = s->pos->moovey + s->ray->diffy;
		y = s->ray->inty / SPACE;
		s->ray->save1 = sqrtf(powf(s->ray->diffx, 2) + powf(s->ray->diffy, 2));
		if (y >= s->width || x >= s->high || y < 0 || x < 0)
			break ;
		if (s->map[x][y]->envi > 1001)
			break ;
		if (s->pos->doorx == 1)
			break ;
	}
}

void	ft_dir_raycasting2y(t_s *s, float angle2, int x, int y)
{
	while (1)
	{
		if (s->map[x][y]->envi == 1000 && (s->pos->moovey - SPACE / 2) < y
		* SPACE)
		{
			s->ray->inty2 = y * SPACE + SPACE / 2;
			s->pos->doory = 1;
		}
		else
		{
			y++;
			s->ray->inty2 = y * SPACE;
		}
		s->ray->diffy = s->ray->inty2 - s->pos->moovey;
		s->ray->diffx = tan(angle2) * s->ray->diffy;
		s->ray->intx2 = s->pos->moovex + s->ray->diffx;
		x = s->ray->intx2 / SPACE;
		s->ray->save2 = sqrtf(powf(s->ray->diffx, 2) + powf(s->ray->diffy, 2));
		if (y >= s->width || x >= s->high || y < 0 || x < 0)
			break ;
		if (s->map[x][y]->envi > 1001)
			break ;
		if (s->pos->doory == 1)
			break ;
	}
}

void	ft_dir_raycasting1(t_s *s, float angle, float angle2)
{
	int		x;
	int		y;

	s->pos->doorx = 0;
	s->pos->doory = 0;
	y = s->pos->moovey / SPACE;
	x = s->pos->moovex / SPACE;
	if (s->pos->dirplayer <= 90)
	{
		ft_dir_raycasting1x(s, angle, x, y);
		y = s->pos->moovey / SPACE;
		x = s->pos->moovex / SPACE;
		ft_dir_raycasting1y(s, angle2, x, y);
	}
	else
	{
		ft_dir_raycasting2x(s, angle, x, y);
		y = s->pos->moovey / SPACE;
		x = s->pos->moovex / SPACE;
		ft_dir_raycasting2y(s, angle2, x, y);
	}
}
