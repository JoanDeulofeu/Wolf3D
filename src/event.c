#include "wolf3d.h"

void	ft_display(t_s *s)
{
	int		x;
	int		y;

	ft_draw_minimap(s);
	ft_rcasting(s);
	if (s->window)
	{
		char cont = 1;
		SDL_Event event;
		while (cont != 0)
		{
			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_KEYDOWN)
				{
					if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
					{
						SDL_DestroyTexture(s->tex->wall);
						SDL_DestroyTexture(s->tex->ground);
						SDL_DestroyTexture(s->tex->player);
						cont = 0;
						break;
					}
					if (event.key.keysym.scancode == SDL_SCANCODE_P)
					{
						ft_dir_player(s, 1);
						ft_rcasting(s);
						ft_draw_minimap(s);
						s->ray->texorcolor = s->ray->texorcolor == 0 ? 1 : 0;
					}
					if (event.key.keysym.scancode == SDL_SCANCODE_W)
					{
						ft_dir_player(s, 1);
						ft_rcasting(s);
						ft_draw_minimap(s);
					}
					if (event.key.keysym.scancode == SDL_SCANCODE_S)
					{
						ft_dir_player(s, 2);
						ft_rcasting(s);
						ft_draw_minimap(s);
					}
					if (event.key.keysym.scancode == SDL_SCANCODE_D)
					{
						ft_dir_player(s, 3);
						ft_rcasting(s);
						ft_draw_minimap(s);
					}
					if (event.key.keysym.scancode == SDL_SCANCODE_A)
					{
						ft_dir_player(s, 4);
						ft_rcasting(s);
						ft_draw_minimap(s);
					}
					if (event.key.keysym.scancode == SDL_SCANCODE_E) //ouverture porte
					{
						y = (s->pos->floaty + SPACE / 8) / SPACE;
						x = (s->pos->floatx + SPACE / 8) / SPACE;
						if (s->map[x][y]->envi == 1000 || s->map[x][y]->envi == 1001)
						{
							s->map[x][y]->envi = 0;
						}
						ft_rcasting(s);
						ft_draw_minimap(s);
					}
					if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT)
					{
						s->pos->dirplayer += 10;
						if (s->pos->dirplayer >= 360)
							s->pos->dirplayer = 0;
						ft_rcasting(s);
						ft_draw_minimap(s);
					}
					if (event.key.keysym.scancode == SDL_SCANCODE_LEFT)
					{
						s->pos->dirplayer -= 10;
						if (s->pos->dirplayer < 0)
							s->pos->dirplayer = 350;
						ft_rcasting(s);
						ft_draw_minimap(s);
					}
					if (event.key.keysym.scancode == SDL_SCANCODE_DOWN)
						if (s->pos->eyehigh > -120)
							s->pos->eyehigh -= 10;
					if (event.key.keysym.scancode == SDL_SCANCODE_UP)
						if (s->pos->eyehigh < 120)
							s->pos->eyehigh += 10;
				}
			}
		}
	}
}
