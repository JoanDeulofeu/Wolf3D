#include "wolf3d.h"

void	ft_init_struct(t_s *s)
{
	int x;
	int y;
	SDL_Renderer *render;
	SDL_Window *window;
	x = 0;
	y = 0;
	if (!(s->map = (t_map***)malloc(sizeof(t_map**) * s->high + 1)))
		ft_usage(-1);
	s->map[s->high] = NULL;
	while (x < s->high)
	{
		if (!(s->map[x] = (t_map**)malloc(sizeof(t_map*) * s->width)))
			ft_usage(-1);
		while (y < s->width)
		{
			if (!(s->map[x][y] = (t_map *)malloc(sizeof(t_s))))
				ft_usage(-1);
			y++;
		}
		y = 0;
		x++;
	}
	SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HIGH, 0, &window, &render);
	s->render = render;
	s->window = window;
	if (!(s->inv = (t_inv*)malloc(sizeof(t_inv))))
		ft_usage(-1);
	if (!(s->pos = (t_pos*)malloc(sizeof(t_pos))))
		ft_usage(-1);
	if (!(s->tex = (t_tex*)malloc(sizeof(t_inv))))
		ft_usage(-1);
	if (!(s->ray = (t_ray*)malloc(sizeof(t_ray))))
		ft_usage(-1);
	s->pos->initplayer = 0;
	s->pos->eyehigh = 0;
	s->ray->texorcolor = 0;
	s->tex->wall = SDL_CreateTexture(s->render, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET,SPACE,SPACE);
	ft_draw_rect(s, s->tex->wall, SPACE, SPACE);
	s->tex->ground = SDL_CreateTexture(s->render, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET,SPACE,SPACE);
	ft_draw_rect(s, s->tex->ground, SPACE, SPACE);
	s->tex->door = SDL_CreateTexture(s->render, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET,SPACE,SPACE);
	s->tex->portal = SDL_CreateTexture(s->render, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET,SPACE,SPACE);
	SDL_SetRenderTarget(s->render, NULL);
}
