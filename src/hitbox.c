#include <wolf3d.h>

/* 8 = taille de la hitbox */

int		ft_hitbox(t_s *s, int key)
{
	int		x;
	int		y;


	y = s->pos->yplayer / SPACE;
	x = s->pos->xplayer / SPACE;
	// printf("\033[33m%d > %d\033[0m\n", s->pos->xplayer - 8, x * SPACE);
	if (key == 4)
	{
		x = (s->pos->xplayer - 9 )/ SPACE;
		printf("\033[33m%d > %d\033[0m\n", s->pos->xplayer - 8, x * SPACE);
		if ((s->pos->xplayer - 8) > (x * SPACE) && s->map[x][y]->envi > 999)
			return (0);
	}
	if (key == 3)
	{
		x = (s->pos->xplayer + 9 )/ SPACE;
		printf("\033[33m%d < %d\033[0m\n", s->pos->xplayer + 8, (x+1) * SPACE);
		if ((s->pos->xplayer + 8) < (x * SPACE) && s->map[x][y]->envi > 999)
			return (0);
	}
	if (key == 1)
	{
		y = (s->pos->yplayer - 9 )/ SPACE;
		if ((s->pos->yplayer - 8) > (y * SPACE) && s->map[x][y]->envi > 999)
			return (0);
	}
	if (key == 2)
	{
		y = (s->pos->yplayer + 9 )/ SPACE;
		if ((s->pos->yplayer + 8) < ((y + 1) * SPACE) && s->map[x][y]->envi > 999)
			return (0);
	}
	printf("\033[32mYOU CAN MOVE\033[0m\n");
	return (1);
}
