/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgehin <jgehin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 12:15:55 by jgehin            #+#    #+#             */
/*   Updated: 2019/03/18 14:06:58 by jgehin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_choise_drawcolor(t_s *s)
{
	if (s->pos->nsew == 1)
		SDL_SetRenderDrawColor(s->render, 220, 60, 60, 255);
	if (s->pos->nsew == 2)
		SDL_SetRenderDrawColor(s->render, 70, 220, 220, 255);
	if (s->pos->nsew == 3)
		SDL_SetRenderDrawColor(s->render, 240, 240, 50, 255);
	if (s->pos->nsew == 4)
		SDL_SetRenderDrawColor(s->render, 60, 230, 60, 255);
}

t_cas	*ft_post_rcasting(t_s *s)
{
	t_cas		*c;

	if (!(c = (t_cas*)malloc(sizeof(t_cas))))
		ft_usage(1);
	c->hr = (WINDOW_HIGH / 2) + s->pos->eyehigh;
	c->x = -1;
	c->savedir = s->pos->dirplayer;
	c->avc = ((float)60) / ((float)WINDOW_WIDTH);
	s->pos->dirplayer = s->pos->dirplayer - ((WINDOW_WIDTH / 2) *
		c->avc + c->avc);
	c->angle = 30 + c->avc;
	c->swich = 0;
	s->pos->dirplayer = (s->pos->dirplayer >= 0) ? s->pos->dirplayer :
		360 + s->pos->dirplayer;
	c->position.x = 0;
	c->position.y = 0;
	c->position.w = WINDOW_WIDTH;
	c->position.h = WINDOW_HIGH;
	s->tex->screen = SDL_CreateTexture(s->render, SDL_PIXELFORMAT_RGBA8888,
		SDL_TEXTUREACCESS_TARGET, WINDOW_WIDTH, WINDOW_HIGH);
	return (c);
}

t_cas	*ft_wall_casting(t_s *s, t_cas *c)
{
	if (s->ray->texorcolor == 0)
	{
		ft_choise_drawcolor(s);
		while (c->y < c->xend)
			SDL_RenderDrawPoint(s->render, c->x, c->y++);
	}
	else
	{
		s->n1->x = c->x;
		s->n1->y = c->xbegin < 0 ? c->y + c->xbegin : c->y;
		s->n1->savey = s->n1->y;
		s->n1->xend = c->xend;
		s->n1->hp = c->hp;
		c->y = ft_choise_drawtex(s);
	}
	return (c);
}

t_cas	*ft_so_calcul(t_s *s, t_cas *c)
{
	s->pos->dirplayer += c->avc;
	s->pos->dirplayer = (s->pos->dirplayer < 360) ?
		s->pos->dirplayer : 0 + s->pos->dirplayer - 360;
	c->dis = ft_dir_raycasting(s);
	c->dis = (c->dis <= 0) ? 1 : c->dis;
	if (c->angle - c->avc > 0 && c->swich == 0)
		c->angle = c->angle - c->avc;
	else
	{
		if (c->swich == 0)
			c->angle = 0;
		c->swich = 1;
		c->angle = c->angle + c->avc;
	}
	c->dis = c->dis * cos(c->angle * M_PI / 180);
	c->hp = (20 * (400 / c->dis));
	c->xbegin = c->hr - c->hp / 2;
	c->xend = c->hr + c->hp / 2 > 800 ? 800 : c->hr + c->hp / 2;
	c->y = 0;
	SDL_SetRenderDrawColor(s->render, 160, 160, 160, 255);
	SDL_SetRenderTarget(s->render, s->tex->screen);
	while (c->y < c->xbegin)
		SDL_RenderDrawPoint(s->render, c->x, c->y++);
	c = ft_wall_casting(s, c);
	return (c);
}

void	ft_rcasting(t_s *s)
{
	t_cas		*c;

	c = ft_post_rcasting(s);
	while (++c->x < WINDOW_WIDTH)
	{
		c = ft_so_calcul(s, c);
		SDL_SetRenderDrawColor(s->render, 110, 60, 20, 255);
		while (c->y < WINDOW_HIGH - 1)
			SDL_RenderDrawPoint(s->render, c->x, c->y++);
	}
	SDL_SetRenderTarget(s->render, NULL);
	SDL_RenderCopy(s->render, s->tex->screen, NULL, &c->position);
	s->pos->dirplayer = c->savedir;
	ft_memdel((void **)&c);
}
