#include "wolf3d.h"

void	ft_rcasting(t_s *s)
{
	int			dis;
	int			hr = WINDOW_HIGH / 2; //hauteur reel, centre de la vision
	int			xbegin;
	int			xend;
	int			x;
	int			y;
	int			hp; // hauteur percu
	float		savedir;
	float		avcmnt; // avancement du dirplayer
	SDL_Rect 	position;

	x = -1;
	savedir = s->pos->dirplayer;
	avcmnt = 100 / WINDOW_WIDTH; // un quart de vision sur les 400 possibles dans dirplayer, 0.125 pour 800 de WINDOW_WIDTH
	s->pos->dirplayer -= WINDOW_WIDTH/2 * avcmnt + avcmnt; // je place dirplayer au bon endroit
	s->pos->dirplayer = (s->pos->dirplayer >= 0) ? s->pos->dirplayer : 400 + s->pos->dirplayer; // je remet dirplayer en dessous 400 si necessaire (400 equivalent au 360degres et non a WINDOW_WIDTH/2)
	position.x = 0;
	position.y = 0;
	position.w = WINDOW_WIDTH;
	position.h = WINDOW_HIGH;
	s->tex->screen = SDL_CreateTexture(s->render, SDL_PIXELFORMAT_RGBA8888,
		SDL_TEXTUREACCESS_TARGET, WINDOW_WIDTH, WINDOW_HIGH);
	while (++x < WINDOW_WIDTH)
	{
		s->pos->dirplayer += avcmnt;
		s->pos->dirplayer = (s->pos->dirplayer < 400) ? s->pos->dirplayer : 0 + s->pos->dirplayer - 400; //(400 equivalent au 360degres et non a WINDOW_WIDTH/2)
		ft_dir_raycasting(s, 1);
		dis = ft_sqrt(pow(s->pos->xplayer - s->pos->moovex, 2) + pow(s->pos->yplayer - s->pos->moovey, 2));
		dis = (dis <= 0) ? 1 : dis;
		hp = 20 * (400 / dis); //20=distance ecran *** 400=hauteur du mur defini
		xbegin = hr - hp / 2;
		xend = hr + hp / 2;
		y = 0;
		SDL_SetRenderDrawColor(s->render,160,160,160,255); //gris
		SDL_SetRenderTarget(s->render, s->tex->screen);
		while (y < xbegin)
			SDL_RenderDrawPoint(s->render, x, y++);
		SDL_SetRenderDrawColor(s->render,200,200,0,255); //jaune deguelasse
		while (y < xend)
			SDL_RenderDrawPoint(s->render, x, y++);
		SDL_SetRenderDrawColor(s->render,150,70,0,255); //marron vraiment deguelasse
		while (y < WINDOW_HIGH - 1)
			SDL_RenderDrawPoint(s->render, x, y++);
	}
	SDL_SetRenderTarget(s->render, NULL);
	SDL_RenderCopy(s->render, s->tex->screen, NULL, &position);
	SDL_RenderPresent(s->render);
	s->pos->dirplayer = savedir; 
}
