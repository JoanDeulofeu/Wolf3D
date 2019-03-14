#include "wolf3d.h"

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
	surface_door = SDL_LoadBMP("textures/door.bmp");
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
			if (s->map[x][y]->envi > 1001)
				SDL_RenderCopy(s->render, s->tex->wall, NULL, &position);
			else if (s->map[x][y]->envi == 1000 || s->map[x][y]->envi == 1001)
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
	s->pos->posplayer.w = 4;
	s->pos->posplayer.h = 4;
	SDL_RenderCopy(s->render, s->tex->player, NULL, &s->pos->posplayer);
	SDL_RenderPresent(s->render);
}
