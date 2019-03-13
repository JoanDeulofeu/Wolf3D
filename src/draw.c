#include "wolf3d.h"


void	ft_draw_rect(t_s *s, SDL_Texture *txr, int high, int width)
{
	int x;
	int y;

	x = 0;
	y = 0;
	if (txr == s->tex->ground)
		SDL_SetRenderDrawColor(s->render,180,180,180,255);
	else
		SDL_SetRenderDrawColor(s->render,155,30,30,255);
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
}

void	ft_init_draw(t_s *s, SDL_Rect position, int x, int y)
{
	s->pos->dirplayer = (s->map[x][y]->item - 2) * 90;
	s->pos->posplayer.x = position.x;
	s->pos->floatx = s->pos->posplayer.x;
	s->pos->posplayer.y = position.y;
	s->pos->floaty = s->pos->posplayer.y;
	s->pos->initplayer++;
}

void	ft_draw_minimap(t_s *s)
{
	int				y;
	int				x;
	int				space;
	SDL_Rect 		position;
	SDL_Surface		*surface_door;

	space = SPACE;
	x = 0;
	surface_door = SDL_LoadBMP("textures/door.tga");
	s->tex->door = SDL_CreateTextureFromSurface(s->render, surface_door);
	while (x < s->high)
	{
		y = 0;
		while (y < s->width)
		{
			position.x = x * space;
			position.y = y * space;
			position.w = space;
			position.h = space;
			if (s->map[x][y]->envi > 1049)
				SDL_RenderCopy(s->render, s->tex->wall, NULL, &position);
			else if (s->map[x][y]->envi > 999 && s->map[x][y]->envi < 1050)
				SDL_RenderCopy(s->render, s->tex->door, NULL, &position);
			else
			{
				SDL_RenderCopy(s->render, s->tex->ground, NULL, &position);
				if ((s->map[x][y]->item > 1 && s->map[x][y]->item < 6) && s->pos->initplayer == 0)
					ft_init_draw(s, position, x, y);
			}
			y++;
		}
		x++;
	}
	x = -1;
	// ft_putstr("##--## TEST 0 ##--##\n");
	s->pos->posplayer.w = SPACE;
	s->pos->posplayer.h = SPACE;
	// ft_putstr("##--## TEST 1 ##--##\n");
	SDL_RenderCopy(s->render, s->tex->player, NULL, &s->pos->posplayer);
	// ft_putstr("##--## TEST 2 ##--##\n");
	SDL_RenderPresent(s->render);
}
