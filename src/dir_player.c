/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 16:19:01 by fmerding          #+#    #+#             */
/*   Updated: 2019/03/15 16:19:32 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_dir_player1(t_s *s, float savex, float savey)
{
	s->pos->floaty -= (1 - (s->pos->dirplayer / 90));
	if (ft_hitbox(s, 1))
	{
		if (s->pos->floaty < s->pos->posplayer.y - 0.5)
			s->pos->posplayer.y--;
	}
	else
		s->pos->floaty = savey;
	if (s->pos->tp == 0)
	{
		s->pos->floatx += (s->pos->dirplayer / 90);
		if (ft_hitbox(s, 3))
		{
			if (s->pos->floatx > s->pos->posplayer.x + 0.5)
				s->pos->posplayer.x++;
		}
		else
			s->pos->floatx = savex;
	}
}

void	ft_dir_player2(t_s *s, float savex, float savey)
{
	s->pos->floaty += ((s->pos->dirplayer - 90) / 90);
	if (ft_hitbox(s, 2))
	{
		if (s->pos->floaty > s->pos->posplayer.y + 0.5)
			s->pos->posplayer.y++;
	}
	else
		s->pos->floaty = savey;
	if (s->pos->tp == 0)
	{
		s->pos->floatx += (1 - ((s->pos->dirplayer - 90) / 90));
		if (ft_hitbox(s, 3))
		{
			if (s->pos->floatx > s->pos->posplayer.x + 0.5)
				s->pos->posplayer.x++;
		}
		else
			s->pos->floatx = savex;
	}
}

void	ft_dir_player3(t_s *s, float savex, float savey)
{
	s->pos->floaty += (1 - ((s->pos->dirplayer - 180) / 90));
	if (ft_hitbox(s, 2))
	{
		if (s->pos->floaty > s->pos->posplayer.y + 0.5)
			s->pos->posplayer.y++;
	}
	else
		s->pos->floaty = savey;
	if (s->pos->tp == 0)
	{
		s->pos->floatx -= ((s->pos->dirplayer - 180) / 90);
		if (ft_hitbox(s, 4))
		{
			if (s->pos->floatx < s->pos->posplayer.x - 0.5)
				s->pos->posplayer.x--;
		}
		else
			s->pos->floatx = savex;
	}
}

void	ft_dir_player4(t_s *s, float savex, float savey)
{
	s->pos->floaty -= ((s->pos->dirplayer - 270) / 90);
	if (ft_hitbox(s, 1))
	{
		if (s->pos->floaty < s->pos->posplayer.y - 0.5)
			s->pos->posplayer.y--;
	}
	else
		s->pos->floaty = savey;
	if (s->pos->tp == 0)
	{
		s->pos->floatx -= (1 - ((s->pos->dirplayer - 270) / 90));
		if (ft_hitbox(s, 4))
		{
			if (s->pos->floatx < s->pos->posplayer.x - 0.5)
				s->pos->posplayer.x--;
		}
		else
			s->pos->floatx = savex;
	}
}

void	ft_dir_player(t_s *s, int i)
{
	int		tmp;
	float	savex;
	float	savey;
	int		v;

	v = s->speed;
	tmp = s->pos->dirplayer;
	ft_change_dir(s, i);
	savey = s->pos->floaty;
	savex = s->pos->floatx;
	while (s->pos->dirplayer <= 90 && v-- > 0)
		ft_dir_player1(s, savex, savey);
	while (s->pos->dirplayer > 90 && s->pos->dirplayer <= 180 && v-- > 0)
		ft_dir_player2(s, savex, savey);
	while (s->pos->dirplayer > 180 && s->pos->dirplayer <= 270 && v-- > 0)
		ft_dir_player3(s, savex, savey);
	while (s->pos->dirplayer > 270 && s->pos->dirplayer <= 360 && v-- > 0)
		ft_dir_player4(s, savex, savey);
	s->pos->dirplayer = tmp;
}
