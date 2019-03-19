/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 18:29:48 by fmerding          #+#    #+#             */
/*   Updated: 2019/03/19 11:18:00 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_init_draw(t_s *s, SDL_Rect position, int x, int y)
{
	s->pos->dirplayer = (s->map[x][y]->item - 2) * 90;
	s->pos->posplayer.x = position.x + SPACE / 2 - 1;
	s->pos->floatx = s->pos->posplayer.x;
	s->pos->posplayer.y = position.y + SPACE / 2 - 1;
	s->pos->floaty = s->pos->posplayer.y;
	s->pos->initplayer++;
}

void	ft_draw_minimap3(t_s *s)
{
	s->pos->posplayer.w = 4;
	s->pos->posplayer.h = 4;
	SDL_RenderCopy(s->render, s->tex->player, NULL, &s->pos->posplayer);
	SDL_RenderPresent(s->render);
}

void	ft_draw_minimap2(t_s *s, SDL_Rect position, int x, int y)
{
	SDL_RenderCopy(s->render, s->tex->ground, NULL, &position);
	if ((s->map[x][y]->item > 1 && s->map[x][y]->item
	< 6) && s->pos->initplayer == 0)
		ft_init_draw(s, position, x, y);
}

void	ft_draw_minimap(t_s *s)
{
	int			y;
	int			x;
	SDL_Rect	position;

	x = -1;
	while (++x < s->high)
	{
		y = -1;
		while (++y < s->width)
		{
			position.x = x * SPACE;
			position.y = y * SPACE;
			position.w = SPACE;
			position.h = SPACE;
			if (s->map[x][y]->envi > 1001)
				SDL_RenderCopy(s->render, s->tex->wall, NULL, &position);
			else if (s->map[x][y]->envi < 1000)
				ft_draw_minimap2(s, position, x, y);
			else
				SDL_RenderCopy(s->render, s->tex->door, NULL, &position);
		}
	}
	ft_draw_minimap3(s);
}
