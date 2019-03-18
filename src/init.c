/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 18:51:10 by fmerding          #+#    #+#             */
/*   Updated: 2019/03/18 15:09:43 by jgehin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_draw_rect(t_s *s, SDL_Texture *txr, int high, int width)
{
	int x;
	int y;

	x = 0;
	y = 0;
	if (txr == s->tex->ground)
		SDL_SetRenderDrawColor(s->render, 180, 180, 180, 255);
	else if (txr == s->tex->player)
		SDL_SetRenderDrawColor(s->render, 20, 70, 20, 255);
	else if (txr == s->tex->wall)
		SDL_SetRenderDrawColor(s->render, 155, 30, 30, 255);
	else if (txr == s->tex->door)
		SDL_SetRenderDrawColor(s->render, 200, 200, 0, 255);
	SDL_SetRenderTarget(s->render, txr);
	while (y != high)
	{
		while (x != width)
		{
			SDL_RenderDrawPoint(s->render, x, y);
			x++;
		}
		x = 0;
		y++;
	}
	SDL_SetRenderTarget(s->render, NULL);
}

void	ft_init_map(t_s *s)
{
	int x;
	int y;

	x = 0;
	y = 0;
	if (!(s->map = (t_map***)malloc(sizeof(t_map**) * (s->high + 1))))
		ft_usage(-1);
	s->map[s->high] = NULL;
	while (x < s->high)
	{
		if (!(s->map[x] = (t_map**)malloc(sizeof(t_map*) * s->width)))
			ft_usage(-1);
		while (y < s->width)
		{
			if (!(s->map[x][y] = (t_map *)malloc(sizeof(t_s))))
				ft_usage(-1);
			y++;
		}
		y = 0;
		x++;
	}
}

void	ft_init_struct2(t_s *s)
{
	s->tex->wall = SDL_CreateTexture(s->render,
	SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, SPACE, SPACE);
	ft_draw_rect(s, s->tex->wall, SPACE, SPACE);
	s->tex->ground = SDL_CreateTexture(s->render,
	SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, SPACE, SPACE);
	ft_draw_rect(s, s->tex->ground, SPACE, SPACE);
	s->tex->door = SDL_CreateTexture(s->render,
	SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, SPACE, SPACE);
	ft_draw_rect(s, s->tex->door, SPACE, SPACE);
	s->tex->player = SDL_CreateTexture(s->render,
	SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 4, 4);
	ft_draw_rect(s, s->tex->player, 4, 4);
	s->tex->wall1 = (ft_tga_to_str("textures/wall_brick.tga", 1));
	s->tex->wall2 = (ft_tga_to_str("textures/wall_cobble.tga", 1));
	s->tex->wall3 = (ft_tga_to_str("textures/wall_dropper.tga", 1));
	s->tex->wall4 = (ft_tga_to_str("textures/wall_sticky.tga", 1));
	s->tex->wall5 = (ft_tga_to_str("textures/wall_door1.tga", 1));
}

void	ft_init_struct(t_s *s)
{
	SDL_Renderer	*render;
	SDL_Window		*window;

	SDL_Init(SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HIGH, 0, &window, &render);
	s->render = render;
	s->window = window;
	if (!(s->inv = (t_inv*)malloc(sizeof(t_inv))))
		ft_usage(-1);
	if (!(s->pos = (t_pos*)malloc(sizeof(t_pos))))
		ft_usage(-1);
	if (!(s->tex = (t_tex*)malloc(sizeof(t_tex))))
		ft_usage(-1);
	if (!(s->ray = (t_ray*)malloc(sizeof(t_ray))))
		ft_usage(-1);
	if (!(s->n1 = (t_n1*)malloc(sizeof(t_n1))))
		ft_usage(-1);
	s->pos->initplayer = 0;
	s->pos->eyehigh = 0;
	s->ray->texorcolor = 1;
	s->speed = SPEED;
	s->cont = 1;
	ft_init_struct2(s);
}
