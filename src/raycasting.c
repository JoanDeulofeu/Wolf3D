#include "wolf3d.h"

void	ft_choise_drawcolor(t_s *s)
{
	if (s->pos->nsew == 1)
		SDL_SetRenderDrawColor(s->render, 220, 60, 60, 255);
	if (s->pos->nsew == 2)
		SDL_SetRenderDrawColor(s->render, 70, 220, 220, 255);
	if (s->pos->nsew == 3)
		SDL_SetRenderDrawColor(s->render, 240, 240, 50, 255);
	if (s->pos->nsew == 4)
		SDL_SetRenderDrawColor(s->render, 60, 230, 60, 255);
}

void	ft_rcasting(t_s *s)
{
	float		dis;
	int			hr;
	int			xbegin;
	int			xend;
	int			x;
	int			y;
	int			hp;
	float		savedir;
	float		avcmnt;
	SDL_Rect	position;
	float		angle;
	int			swich;

	hr = (WINDOW_HIGH / 2) + s->pos->eyehigh;
	x = -1;
	savedir = s->pos->dirplayer;
	avcmnt = ((float)60) / ((float)WINDOW_WIDTH);
	s->pos->dirplayer = s->pos->dirplayer - ((WINDOW_WIDTH / 2) * avcmnt + avcmnt);
	angle = 30 + avcmnt;
	swich = 0;
	s->pos->dirplayer = (s->pos->dirplayer >= 0) ? s->pos->dirplayer : 360 + s->pos->dirplayer;
	position.x = 0;
	position.y = 0;
	position.w = WINDOW_WIDTH;
	position.h = WINDOW_HIGH;
	s->tex->screen = SDL_CreateTexture(s->render, SDL_PIXELFORMAT_RGBA8888,
		SDL_TEXTUREACCESS_TARGET, WINDOW_WIDTH, WINDOW_HIGH);
	while (++x < WINDOW_WIDTH)
	{
		s->pos->dirplayer += avcmnt;
		s->pos->dirplayer = (s->pos->dirplayer < 360) ? s->pos->dirplayer : 0 + s->pos->dirplayer - 360;
		dis = ft_dir_raycasting(s);
		dis = (dis <= 0) ? 1 : dis;
		if (angle - avcmnt > 0 && swich == 0)
			angle = angle - avcmnt;
		else
		{
			if (swich == 0)
				angle = 0;
			swich = 1;
			angle = angle + avcmnt;
		}
		dis = dis * cos(angle * M_PI / 180);
		hp = (20 * (400 / dis));
		xbegin = hr - hp / 2;
		xend = hr + hp / 2;
		s->compens = xbegin < 0 ? ft_abs(xbegin) : 0;
		printf("xbegin %d  ", xbegin);
		y = 0;
		SDL_SetRenderDrawColor(s->render, 160, 160, 160, 255);
		SDL_SetRenderTarget(s->render, s->tex->screen);
		while (y < xbegin)
			SDL_RenderDrawPoint(s->render, x, y++);
		if (s->ray->texorcolor == 0)
		{
			ft_choise_drawcolor(s);
			while (y < xend)
				SDL_RenderDrawPoint(s->render, x, y++);
		}
		else
			y = ft_choise_drawtex(s, x, y, xend, hp);
		SDL_SetRenderDrawColor(s->render, 110, 60, 20, 255);
		while (y < WINDOW_HIGH - 1)
			SDL_RenderDrawPoint(s->render, x, y++);
	}
	SDL_SetRenderTarget(s->render, NULL);
	SDL_RenderCopy(s->render, s->tex->screen, NULL, &position);
	s->pos->dirplayer = savedir;
}
