#include <wolf3d.h>


void	ft_draw_rect(t_s *s, SDL_Texture *txr, int high, int width)
{
	int x;
	int y;

	x = 0;
	y = 0;
	if (txr == s->wall)
		SDL_SetRenderDrawColor(s->render,255,30,30,255);
	if (txr == s->ground)
		SDL_SetRenderDrawColor(s->render,130,255,240,255);
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

void	ft_draw_minimap(t_s *s)
{
	int				y;
	int				x;
	int				space;
	SDL_Rect 		position;
	SDL_Surface		*pika;

	space = SPACE;
	x = 0;
	s->wall = SDL_CreateTexture(s->render, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET,space,space);
	ft_draw_rect(s, s->wall, space, space);
	s->ground = SDL_CreateTexture(s->render, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET,space,space);
	ft_draw_rect(s, s->ground, space, space);
	SDL_SetRenderTarget(s->render, NULL);
	while (x < s->high)
	{
		y = 0;
		while (y < s->width)
		{
			position.x = x * space;
			position.y = y * space;
			if (s->map[x][y]->envi > 999)
			{
				SDL_QueryTexture(s->wall, NULL, NULL, &position.w, &position.h);
				SDL_RenderCopy(s->render, s->wall, NULL, &position);
			}
			else
			{
				SDL_QueryTexture(s->ground, NULL, NULL, &position.w, &position.h);
				SDL_RenderCopy(s->render, s->ground, NULL, &position);
				if ((s->map[x][y]->item > 1 && s->map[x][y]->item < 6)&& s->initplayer == 0)
				{
					s->dirplayer = (s->map[x][y]->item - 2) * 100;
					s->posplayer.x = position.x;
					s->floatx = s->posplayer.x;
					s->posplayer.y = position.y;
					s->floaty = s->posplayer.y;
					s->initplayer++;
				}
			}
			y++;
		}
		x++;
	}
	if(!(pika = SDL_LoadBMP("Pikapika.bmp")))
	    ft_usage(6);
	s->player = SDL_CreateTextureFromSurface(s->render, pika);
	SDL_FreeSurface(s->pika);
	// SDL_QueryTexture(s->player, NULL, NULL, &s->posplayer.w, &s->posplayer.h);
	s->posplayer.h = space / 4;
	s->posplayer.w = space / 4;
	SDL_RenderCopy(s->render, s->player, NULL, &s->posplayer);
	SDL_RenderPresent(s->render);
}
