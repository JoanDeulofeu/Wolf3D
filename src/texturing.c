/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgehin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:05:10 by jgehin            #+#    #+#             */
/*   Updated: 2019/03/18 11:05:14 by jgehin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

SDL_Color	ft_clr(int x, int y, unsigned char *str)
{
	SDL_Color	color;
	int			coord;

	coord = (x + y * 64) * 4;
	color.r = str[coord];
	color.g = str[coord + 1];
	color.b = str[coord + 2];
	color.a = str[coord + 3];
	return (color);
}

void		ft_just_draw(t_s *s, SDL_Color clr)
{
	SDL_SetRenderDrawColor(s->render, clr.b, clr.g, clr.r, clr.a);
	SDL_RenderDrawPoint(s->render, s->n1->x, s->n1->y++);
}

int			ft_south_east(t_s *s)
{
	SDL_Color		clr;

	if (s->pos->nsew == 1)
	{
		s->n1->xtex = ((fmodf(s->ray->savex, SPACE)) * 100 / SPACE) * 64 / 100;
		while (s->n1->y < s->n1->xend)
		{
			s->n1->ytex = (s->n1->y - s->n1->savey) * 64 / s->n1->hp;
			clr = s->pos->door == 0 ? ft_clr(s->n1->xtex, s->n1->ytex,
			s->tex->wall1) : ft_clr(s->n1->xtex, s->n1->ytex, s->tex->wall5);
			ft_just_draw(s, clr);
		}
	}
	if (s->pos->nsew == 2)
	{
		s->n1->xtex = ((fmodf(s->ray->savey, SPACE)) * 100 / SPACE) * 64 / 100;
		while (s->n1->y < s->n1->xend)
		{
			s->n1->ytex = (s->n1->y - s->n1->savey) * 64 / s->n1->hp;
			clr = s->pos->door == 0 ? ft_clr(s->n1->xtex, s->n1->ytex,
			s->tex->wall2) : ft_clr(s->n1->xtex, s->n1->ytex, s->tex->wall5);
			ft_just_draw(s, clr);
		}
	}
	return (s->n1->y);
}

int			ft_north_west(t_s *s)
{
	SDL_Color		clr;

	if (s->pos->nsew == 3)
	{
		s->n1->xtex = ((fmodf(s->ray->savex, SPACE)) * 100 / SPACE) * 64 / 100;
		while (s->n1->y < s->n1->xend)
		{
			s->n1->ytex = (s->n1->y - s->n1->savey) * 64 / s->n1->hp;
			clr = s->pos->door == 0 ? ft_clr(s->n1->xtex, s->n1->ytex,
			s->tex->wall3) : ft_clr(s->n1->xtex, s->n1->ytex, s->tex->wall5);
			ft_just_draw(s, clr);
		}
	}
	if (s->pos->nsew == 4)
	{
		s->n1->xtex = (fmodf(s->ray->savey, SPACE) * 100 / SPACE) * 64 / 100;
		while (s->n1->y < s->n1->xend)
		{
			s->n1->ytex = (s->n1->y - s->n1->savey) * 64 / s->n1->hp;
			clr = s->pos->door == 0 ? ft_clr(s->n1->xtex, s->n1->ytex,
			s->tex->wall4) : ft_clr(s->n1->xtex, s->n1->ytex, s->tex->wall5);
			ft_just_draw(s, clr);
		}
	}
	return (s->n1->y);
}

int			ft_choise_drawtex(t_s *s)
{
	int y;

	if (s->pos->nsew == 1 || s->pos->nsew == 2)
		y = ft_south_east(s);
	else
		y = ft_north_west(s);
	return (y);
}
