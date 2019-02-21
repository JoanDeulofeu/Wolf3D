#include <wolf3d.h>

/* 8 = taille de la hitbox */

int		ft_hitbox(t_s *s, int key)
{
	int		x;
	int		y;

	x = s->xplayer / SPACE;
	y = s->yplayer / SPACE;
	// printf("\033[33m%d > %d\033[0m\n", s->xplayer - 8, x * SPACE);

	if (key == SDL_SCANCODE_A)
	{
		printf("\033[33m%d > %d\033[0m\n", s->xplayer - 8, x * SPACE);
		if ((s->xplayer - 8) > (x * SPACE) && s->map[x][y]->envi > 999)
			return (0);
	}
	if (key == SDL_SCANCODE_D)
	{
		printf("\033[33m%d < %d\033[0m\n", s->xplayer + 8, (x+1) * SPACE);
		if ((s->xplayer + 8) < ((x + 1) * SPACE) && s->map[x][y]->envi > 999)
			return (0);
	}
	if (key == SDL_SCANCODE_W)
		if ((s->yplayer - 8) > (y * SPACE) && s->map[x][y]->envi > 999)
			return (0);
	if (key == SDL_SCANCODE_S)
		if ((s->yplayer + 8) < ((y + 1) * SPACE) && s->map[x][y]->envi > 999)
			return (0);

	printf("\033[32mYOU CAN MOVE\033[0m\n");
	return (1);
}
