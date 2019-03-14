#include "wolf3d.h"

SDL_Color	ft_getcolor(int x, int y, unsigned char *str)
{
	SDL_Color	color;
	int			coord;

	coord = (x + y * 64) * 4;
	color.r = str[coord];
	color.g = str[coord + 1];
	color.b = str[coord + 2];
	color.a = str[coord + 3];
	// printf("coord=%d / r %d / g %d / b %d / a %d\n", coord, color.r, color.g, color.b, color.a);
	return (color);
}

int			ft_choise_drawtex(t_s *s, int x, int y, int xend, int hp)
{
	float			fpercentx;
	float			fpercenty;
	int				xtex;
	int				ytex;
	int				savey = y;
	SDL_Color		color;
	SDL_PixelFormat *format;

	format = SDL_AllocFormat(SDL_PIXELFORMAT_RGBA8888);
	if (s->pos->nsew == 1)
	{
		fpercentx = (fmodf(s->ray->savex, SPACE)) * 100 / SPACE;
		xtex = fpercentx * 64 /100;
		while (y < xend)
		{
			fpercenty = y * 100 / hp;
			ytex = (y - savey) * 64 / hp;
			color = ft_getcolor(xtex, ytex, s->tex->wall1);
			SDL_SetRenderDrawColor(s->render, color.b, color.g, color.r, color.a);
			SDL_RenderDrawPoint(s->render, x, y++);
		}
	}
	if (s->pos->nsew == 2)
	{
		fpercentx = (fmodf(s->ray->savey, SPACE)) * 100 / SPACE;
		xtex = fpercentx * 64 /100;
		while (y < xend)
		{
			fpercenty = y * 100 / hp;
			ytex = (y - savey) * 64 / hp;
			color = ft_getcolor(xtex, ytex, s->tex->wall2);
			SDL_SetRenderDrawColor(s->render, color.b, color.g, color.r, color.a);
			SDL_RenderDrawPoint(s->render, x, y++);
		}
	}
	if (s->pos->nsew == 3)
	{
		fpercentx = (fmodf(s->ray->savex, SPACE)) * 100 / SPACE;
		xtex = fpercentx * 64 /100;
		while (y < xend)
		{
			fpercenty = y * 100 / hp;
			ytex = (y - savey) * 64 / hp;
			color = ft_getcolor(xtex, ytex, s->tex->wall3);
			SDL_SetRenderDrawColor(s->render, color.b, color.g, color.r, color.a);
			SDL_RenderDrawPoint(s->render, x, y++);
		}
	}
	if (s->pos->nsew == 4)
	{
		fpercentx = (fmodf(s->ray->savey, SPACE)) * 100 / SPACE;
		xtex = fpercentx * 64 /100;
		while (y < xend)
		{
			fpercenty = y * 100 / hp;
			ytex = (y - savey) * 64 / hp;
			color = ft_getcolor(xtex, ytex, s->tex->wall4);
			SDL_SetRenderDrawColor(s->render, color.b, color.g, color.r, color.a);
			SDL_RenderDrawPoint(s->render, x, y++);
		}
	}
	return (y);
}
