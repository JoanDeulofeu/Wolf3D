#include "wolf3d.h"

void	ft_choise_drawcolor(t_s *s)
{
	if (s->pos->nsew == 1)
		SDL_SetRenderDrawColor(s->render,220,60,60,255); //rouge
	if (s->pos->nsew == 2)
		SDL_SetRenderDrawColor(s->render,70,220,220,255); //bleu
	if (s->pos->nsew == 3)
		SDL_SetRenderDrawColor(s->render,240,240,50,255); //jaune
	if (s->pos->nsew == 4)
		SDL_SetRenderDrawColor(s->render,60,230,60,255); //vert
}

void	ft_rcasting(t_s *s)
{
	float		dis;
	int			hr = (WINDOW_HIGH / 2) + s->pos->eyehigh; //hauteur reel, centre de la vision
	int			xbegin;
	int			xend;
	int			x;
	int			y;
	int			hp; // hauteur percu
	float		savedir;
	float		avcmnt; // avancement du dirplayer
	SDL_Rect 	position;
	// float		angle;

	x = -1;
	// angle = 0;
	savedir = s->pos->dirplayer;
	avcmnt = ((float)90) / ((float)WINDOW_WIDTH);
	s->pos->dirplayer = s->pos->dirplayer - ((WINDOW_WIDTH/2) * avcmnt + avcmnt);
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
		// angle = fabsf(((float)savedir) / ((float)s->pos->dirplayer));
		ft_dir_raycasting(s, 1);
		dis = sqrtf(powf(s->pos->xplayer - s->pos->moovex, 2) + powf(s->pos->yplayer - s->pos->moovey, 2));
		dis = (dis <= 0) ? 1 : dis;
		// dis = dis * cos(angle);
		hp = (20 * (400 / dis)); //20=distance ecran *** 400=hauteur du mur defini
		// printf("angle= %f", angle);
		// printf("cos(angle)= %f", cos(angle));
		// printf(",  hp= %d", hp);
		// printf("\n");
		xbegin = hr - hp / 2;
		xend = hr + hp / 2;
		y = 0;
		SDL_SetRenderDrawColor(s->render,160,160,160,255);
		SDL_SetRenderTarget(s->render, s->tex->screen);
		while (y < xbegin)
			SDL_RenderDrawPoint(s->render, x, y++);
		ft_choise_drawcolor(s);
		while (y < xend)
			SDL_RenderDrawPoint(s->render, x, y++);
		SDL_SetRenderDrawColor(s->render,110,60,20,255);
		while (y < WINDOW_HIGH - 1)
			SDL_RenderDrawPoint(s->render, x, y++);
	}
	SDL_SetRenderTarget(s->render, NULL);
	SDL_RenderCopy(s->render, s->tex->screen, NULL, &position);
	SDL_RenderPresent(s->render);
	s->pos->dirplayer = savedir;
}


// printf("dirplayer= %f", s->pos->dirplayer);
// printf(",  xplayer= %f", s->pos->xplayer);
// printf(",  yplayer= %f", s->pos->yplayer);
// printf(",  movex= %f", s->pos->moovex);
// printf(",  movey= %f", s->pos->moovey);
// printf(",  dis= %f", dis);
// printf(",  xbegin= %d", xbegin);
// printf(",  xend= %d", xend);
// printf("\n");
