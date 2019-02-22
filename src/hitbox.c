#include <wolf3d.h>

/* 8 = taille de la hitbox */

int		ft_hitbox(t_s *s, int key)
{
	int		x;
	int		y;


	y = s->pos->floaty / SPACE;
	x = s->pos->floatx / SPACE;//trouver la case
	// printf("\033[33m%d > %d\033[0m\n", s->pos->floaty - 8, x * SPACE);
	if (key == 4)
	{
		if ((s->pos->floatx - 1 ) < (x * SPACE) && s->map[x-1][y]->envi > 999)
			return (0);
	}
	if (key == 3)
	{
		if ((s->pos->floatx + SPACE / 4) >= ((x + 1) * SPACE) && s->map[x+1][y]->envi > 999)
			return (0);
	}
	if (key == 1)
	{
		if ((s->pos->floaty - 1) < (y * SPACE) && s->map[x][y - 1]->envi > 999)
			return (0);
	}
	if (key == 2) // bas
	{
		if ((s->pos->floaty + SPACE / 4) >= ((y + 1) * SPACE) && s->map[x][y + 1]->envi > 999)
			return (0);
	}
	printf("\033[32mYOU CAN MOVE\033[0m\n");
	return (1);
}

int		ft_hitbox_ray(t_s *s, int key)
{
	int		x;
	int		y;


	y = s->pos->moovey / SPACE;
	x = s->pos->moovex / SPACE;//trouver la case
	// printf("\033[33m%d > %d\033[0m\n", s->pos->floaty - 8, x * SPACE);
	if (key == 4)
		if ((s->pos->moovex - 1) < (x * SPACE) && s->map[x-1][y]->envi > 999)
			return (0);
	if (key == 3)
		if ((s->pos->moovex + 1) >= ((x + 1) * SPACE) && s->map[x+1][y]->envi > 999)
			return (0);
	if (key == 1)
		if ((s->pos->moovey - 1) < (y * SPACE) && s->map[x][y - 1]->envi > 999)
			return (0);
	if (key == 2) // bas
		if ((s->pos->moovey + 1) >= ((y + 1) * SPACE) && s->map[x][y + 1]->envi > 999)
			return (0);
	return (1);
}
