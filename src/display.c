#include <wolf3d.h>

void	ft_display(t_s *s)
{
	// int i;
	// SDL_SetRenderDrawColor(s->render, 255, 0, 0, 255);
	// for (i = 0; i < WINDOW_WIDTH; ++i)
	// 	SDL_RenderDrawPoint(s->render, i, i);
	ft_draw_minimap(s);
	// SDL_RenderPresent(s->render);
	if (s->window)
	{
		char cont = 1; /* Détermine si on continue la boucle principale */
		SDL_Event event;
		while (cont != 0)
		{
			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_KEYDOWN)
				{
					if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
					{
						cont = 0;
						break;
					}
				}
			}
		}
	}
}

void	ft_draw_rect(t_s *s, SDL_Texture *txr, int high, int width)
{
	int x;
	int y;

	x = 0;
	y = 0;
	if (txr == s->wall)
		SDL_SetRenderDrawColor(s->render,255,0,0,255);
	if (txr == s->ground)
		SDL_SetRenderDrawColor(s->render,0,255,0,255);
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
	int y;
	int x = 0;
	int space = 50;
	SDL_Rect position;
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
		position.x = y * space;
		position.y = x * space;
		if (s->map[x][y]->envi > 999)
		{
			SDL_QueryTexture(s->wall, NULL, NULL, &position.w, &position.h);
			SDL_RenderCopy(s->render, s->wall, NULL, &position);
		}
		else // si on remets un if je gagne une canette
		{
			SDL_QueryTexture(s->ground, NULL, NULL, &position.w, &position.h);
			SDL_RenderCopy(s->render, s->ground, NULL, &position);
		}
		y++;
		}
	x++;
	}
	SDL_RenderPresent(s->render);
}
