#include "wolf3d.h"

void		ft_choise_drawcolor(t_s *s)
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
	int			hr = (WINDOW_HIGH / 2) + s->pos->eyehigh; //hauteur reel, centre de vision
	int			xbegin;
	int			xend;
	int			x;
	int			y;
	int			hp; // hauteur percu
	float		savedir;
	float		avcmnt; // avancement du dirplayer
	SDL_Rect 	position;
	float		angle;
	int 		swich;

	x = -1;
	savedir = s->pos->dirplayer;
	avcmnt = ((float)60) / ((float)WINDOW_WIDTH);
	s->pos->dirplayer = s->pos->dirplayer - ((WINDOW_WIDTH/2) * avcmnt + avcmnt);
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
		hp = (20 * (400 / dis)); //20=distance ecran *** 400=hauteur du mur defini
		xbegin = hr - hp / 2;
		xend = hr + hp / 2;
		y = 0;
		SDL_SetRenderDrawColor(s->render,160,160,160,255);
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
		SDL_SetRenderDrawColor(s->render,110,60,20,255);
		while (y < WINDOW_HIGH - 1)
			SDL_RenderDrawPoint(s->render, x, y++);
	}
	SDL_SetRenderTarget(s->render, NULL);
	SDL_RenderCopy(s->render, s->tex->screen, NULL, &position);
	s->pos->dirplayer = savedir;
}

float		ft_dir_raycasting(t_s *s)
{
	float tmp;
	float angle;
	float angle2;
	float dis;
	tmp = s->pos->dirplayer;
	s->pos->doorx = 0;
	s->pos->doory = 0;
	s->pos->moovex = s->pos->floatx + SPACE / 8;
	s->pos->moovey = s->pos->floaty + SPACE / 8;
	if (s->pos->dirplayer <= 90)
	{
		angle = ((90 - s->pos->dirplayer) * M_PI / 180);
		angle2 = ((s->pos->dirplayer) * M_PI / 180);
		ft_dir_raycasting1(s, angle, angle2);
		if (s->ray->save1 < s->ray->save2)
		{
			s->pos->nsew = 4;
			dis = s->ray->save1;
			s->ray->savex = s->ray->intx;
			s->ray->savey = s->ray->inty;
			if (s->pos->doorx == 1)
				s->pos->nsew = 5;
		}
		else
		{
			s->pos->nsew = 3;
			dis = s->ray->save2;
			s->ray->savex = s->ray->intx2;
			s->ray->savey = s->ray->inty2;
			if (s->pos->doory == 1)
				s->pos->nsew = 5;
		}
	}
	if (s->pos->dirplayer > 90 && s->pos->dirplayer <= 180)
	{
		angle = ((s->pos->dirplayer - 90) * M_PI / 180);
		angle2 = ((180 - s->pos->dirplayer) * M_PI / 180);
		ft_dir_raycasting2(s, angle, angle2);
		if (s->ray->save1 < s->ray->save2)
		{
			s->pos->nsew = 4;
			dis = s->ray->save1;
			s->ray->savex = s->ray->intx;
			s->ray->savey = s->ray->inty;
			if (s->pos->doorx == 1)
				s->pos->nsew = 5;
		}
		else
		{
			s->pos->nsew = 1;
			dis = s->ray->save2;
			s->ray->savex = s->ray->intx2;
			s->ray->savey = s->ray->inty2;
			if (s->pos->doory == 1)
				s->pos->nsew = 5;
		}

	}
	if (s->pos->dirplayer > 180 && s->pos->dirplayer <= 270)
	{
		angle = ((270 - s->pos->dirplayer) * M_PI / 180);
		angle2 = ((s->pos->dirplayer - 180) * M_PI / 180);
		ft_dir_raycasting3(s, angle, angle2);
		if (s->ray->save1 < s->ray->save2)
		{
			s->pos->nsew = 2;
			dis = s->ray->save1;
			s->ray->savex = s->ray->intx;
			s->ray->savey = s->ray->inty;
			if (s->pos->doorx == 1)
				s->pos->nsew = 5;
		}
		else
		{
			s->pos->nsew = 1;
			dis = s->ray->save2;
			s->ray->savex = s->ray->intx2;
			s->ray->savey = s->ray->inty2;
			if (s->pos->doory == 1)
				s->pos->nsew = 5;
		}
	}
	if (s->pos->dirplayer > 270 && s->pos->dirplayer <= 360)
	{
		angle = ((s->pos->dirplayer - 270) * M_PI / 180);
		angle2 = ((360 - s->pos->dirplayer ) * M_PI / 180);
		ft_dir_raycasting4(s, angle, angle2);
		if (s->ray->save1 < s->ray->save2)
		{
			s->pos->nsew = 2;
			dis = s->ray->save1;
			s->ray->savex = s->ray->intx;
			s->ray->savey = s->ray->inty;
			if (s->pos->doorx == 1)
				s->pos->nsew = 5;
		}
		else
		{
			s->pos->nsew = 3;
			dis = s->ray->save2;
			s->ray->savex = s->ray->intx2;
			s->ray->savey = s->ray->inty2;
			if (s->pos->doory == 1)
				s->pos->nsew = 5;
		}
	}
	// printf("savex=%f     savey= %f   \n", s->ray->savex , s->ray->savey);
	s->pos->dirplayer = tmp;
	return(dis);
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
