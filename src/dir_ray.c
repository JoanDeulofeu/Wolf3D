/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 18:45:32 by fmerding          #+#    #+#             */
/*   Updated: 2019/03/15 18:46:51 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

float		ft_dir_1(t_s *s, float dis)
{
	float angle;
	float angle2;

	angle = ((90 - s->pos->dirplayer) * M_PI / 180);
	angle2 = ((s->pos->dirplayer) * M_PI / 180);
	ft_dir_raycasting1(s, angle, angle2);
	if (s->ray->save1 < s->ray->save2)
	{
		s->pos->nsew = 4;
		dis = s->ray->save1;
		s->ray->savex = s->ray->intx;
		s->ray->savey = s->ray->inty;
		if (s->pos->doorx == 1)
			s->pos->door = 1;
	}
	else
	{
		s->pos->nsew = 3;
		dis = s->ray->save2;
		s->ray->savex = s->ray->intx2;
		s->ray->savey = s->ray->inty2;
		if (s->pos->doory == 1)
			s->pos->door = 1;
	}
	return (dis);
}

float		ft_dir_2(t_s *s, float dis)
{
	float angle;
	float angle2;

	angle = ((s->pos->dirplayer - 90) * M_PI / 180);
	angle2 = ((180 - s->pos->dirplayer) * M_PI / 180);
	ft_dir_raycasting1(s, angle, angle2);
	if (s->ray->save1 < s->ray->save2)
	{
		s->pos->nsew = 4;
		dis = s->ray->save1;
		s->ray->savex = s->ray->intx;
		s->ray->savey = s->ray->inty;
		if (s->pos->doorx == 1)
			s->pos->door = 1;
	}
	else
	{
		s->pos->nsew = 1;
		dis = s->ray->save2;
		s->ray->savex = s->ray->intx2;
		s->ray->savey = s->ray->inty2;
		if (s->pos->doory == 1)
			s->pos->door = 1;
	}
	return (dis);
}

float		ft_dir_3(t_s *s, float dis)
{
	float angle;
	float angle2;

	angle = ((270 - s->pos->dirplayer) * M_PI / 180);
	angle2 = ((s->pos->dirplayer - 180) * M_PI / 180);
	ft_dir_raycasting2(s, angle, angle2);
	if (s->ray->save1 < s->ray->save2)
	{
		s->pos->nsew = 2;
		dis = s->ray->save1;
		s->ray->savex = s->ray->intx;
		s->ray->savey = s->ray->inty;
		if (s->pos->doorx == 1)
			s->pos->door = 1;
	}
	else
	{
		s->pos->nsew = 1;
		dis = s->ray->save2;
		s->ray->savex = s->ray->intx2;
		s->ray->savey = s->ray->inty2;
		if (s->pos->doory == 1)
			s->pos->door = 1;
	}
	return (dis);
}

float		ft_dir_4(t_s *s, float dis)
{
	float angle;
	float angle2;

	angle = ((s->pos->dirplayer - 270) * M_PI / 180);
	angle2 = ((360 - s->pos->dirplayer) * M_PI / 180);
	ft_dir_raycasting2(s, angle, angle2);
	if (s->ray->save1 < s->ray->save2)
	{
		s->pos->nsew = 2;
		dis = s->ray->save1;
		s->ray->savex = s->ray->intx;
		s->ray->savey = s->ray->inty;
		if (s->pos->doorx == 1)
			s->pos->door = 1;
	}
	else
	{
		s->pos->nsew = 3;
		dis = s->ray->save2;
		s->ray->savex = s->ray->intx2;
		s->ray->savey = s->ray->inty2;
		if (s->pos->doory == 1)
			s->pos->door = 1;
	}
	return (dis);
}

float		ft_dir_raycasting(t_s *s)
{
	float tmp;
	float dis;

	dis = 0;
	tmp = s->pos->dirplayer;
	s->pos->door = 0;
	s->pos->moovex = s->pos->floatx + SPACE / 8;
	s->pos->moovey = s->pos->floaty + SPACE / 8;
	if (s->pos->dirplayer <= 90)
		dis = ft_dir_1(s, dis);
	if (s->pos->dirplayer > 90 && s->pos->dirplayer <= 180)
		dis = ft_dir_2(s, dis);
	if (s->pos->dirplayer > 180 && s->pos->dirplayer <= 270)
		dis = ft_dir_3(s, dis);
	if (s->pos->dirplayer > 270 && s->pos->dirplayer <= 360)
		dis = ft_dir_4(s, dis);
	s->pos->dirplayer = tmp;
	return (dis);
}
