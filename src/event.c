/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 17:28:44 by fmerding          #+#    #+#             */
/*   Updated: 2019/03/15 18:29:18 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_display3(t_s *s)
{
	int		x;
	int		y;

	y = (s->pos->floaty + SPACE / 8) / SPACE;
	x = (s->pos->floatx + SPACE / 8) / SPACE;
	if (s->map[x][y]->envi == 1000 || s->map[x][y]->envi ==
	1001)
		s->map[x][y]->envi = 0;
}

void	ft_quit(t_s *s)
{
	SDL_DestroyTexture(s->tex->wall);
	SDL_DestroyTexture(s->tex->ground);
	SDL_DestroyTexture(s->tex->player);
	SDL_DestroyTexture(s->tex->door);
	exit(0);
}

void	ft_display2(t_s *s, SDL_Event event)
{
	if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
		ft_quit(s);
	if (event.key.keysym.scancode == SDL_SCANCODE_P)
		s->ray->texorcolor = s->ray->texorcolor == 0 ? 1 : 0;
	if (event.key.keysym.scancode == SDL_SCANCODE_W)
		ft_dir_player(s, 1);
	if (event.key.keysym.scancode == SDL_SCANCODE_S)
		ft_dir_player(s, 2);
	if (event.key.keysym.scancode == SDL_SCANCODE_D)
		ft_dir_player(s, 3);
	if (event.key.keysym.scancode == SDL_SCANCODE_A)
		ft_dir_player(s, 4);
	if (event.key.keysym.scancode == SDL_SCANCODE_E)
		ft_display3(s);
	if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT)//besoin de william turner.
	{
		s->pos->dirplayer += 10;
		if (s->pos->dirplayer >= 360)
			s->pos->dirplayer = 0;
	}
	if (event.key.keysym.scancode == SDL_SCANCODE_LEFT)//besoin de william turner.
	{
		s->pos->dirplayer -= 10;
		if (s->pos->dirplayer < 0)
			s->pos->dirplayer = 350;
	}
	ft_rcasting(s);
	ft_draw_minimap(s);
}

void	ft_display(t_s *s)
{
	int			timep;
	int			timea;
	SDL_Event	event;

	timep = 0;
	ft_draw_minimap(s);
	ft_rcasting(s);
	ft_draw_minimap(s);
	while (SDL_WaitEvent(&event) && s->cont != 0)
	{
		if (event.type == SDL_QUIT)
			ft_quit(s);
		timea = SDL_GetTicks();
		if (timea - timep < 10)
			SDL_Delay(10 - (timea - timep));
		else
		{
			timep = timea;
			if (event.type == SDL_KEYDOWN)
				ft_display2(s, event);
		}
	}
}
