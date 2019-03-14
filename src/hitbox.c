#include "wolf3d.h"

int		ft_hitbox(t_s *s, int key)
{
	int		x;
	int		y;
	int		x2;
	int		y2;
	int		xc;
	int		yc;

	y = s->pos->floaty / SPACE;
	y2 = (s->pos->floaty + SPACE / 4) / SPACE;
	x = s->pos->floatx / SPACE;
	x2 = (s->pos->floatx + SPACE / 4) / SPACE;
	xc = (s->pos->floatx + SPACE / 8) / SPACE;
	yc = (s->pos->floaty + SPACE / 8) / SPACE;
	if (key == 1 || key == 2 || key == 3 || key == 4)
	{
		if (s->map[x][y]->envi > 1099 || s->map[x][y2]->envi > 1099 ||
		s->map[x2][y]->envi > 1099 || s->map[x2][y2]->envi > 1099)
			return (0);
		if (s->map[xc][yc]->envi > 1049 && s->map[xc][yc]->envi < 1100)
		{
			ft_swap_pos(s, key, xc, yc);
			s->pos->tp = 1;
		}
	}
	if (key == 4)
		if (s->pos->floatx < x * SPACE + SPACE / 2)
			if (s->map[x][y]->envi == 1001 || s->map[x][y2]->envi == 1001)
				return (0);
	if (key == 3)
		if ((s->pos->floatx + SPACE / 4) < x * SPACE + SPACE / 2)
			if (s->map[x2][y]->envi == 1001 || s->map[x2][y2]->envi == 1001)
				return (0);
	if (key == 1)
		if (s->pos->floaty < y * SPACE + SPACE / 2)
			if (s->map[x][y]->envi == 1000 || s->map[x2][y]->envi == 1000)
				return (0);
	if (key == 2)
		if ((s->pos->floaty + SPACE / 4) < y * SPACE + SPACE / 2)
			if (s->map[x2][y]->envi == 1000 || s->map[x][y]->envi == 1000)
				return (0);
	return (1);
}

void	ft_swap_pos(t_s *s, int mode, int x, int y)
{
	int		i;
	int		j;
	int		tp;
	float	diffx;
	float	diffy;

	diffx = 0;
	diffy = 0;
	i = 0;
	j = 0;
	if (mode == 1)
		diffy = 1;
	if (mode == 2)
		diffy = -1;
	if (mode == 3)
		diffx = -1;
	if (mode == 4)
		diffx = 1;
	tp = s->map[x][y]->envi;
	while (j < s->high)
	{
		while (i < s->width)
		{
			if (i != x && j != y)
			{
				if (s->map[i][j]->envi == tp)
				{
					diffx += (x - i);
					diffy += (y - j);
					s->pos->posplayer.x -= (diffx * SPACE);
					s->pos->posplayer.y -= (diffy * SPACE);
					s->pos->floatx -= (diffx * SPACE);
					s->pos->floaty -= (diffy * SPACE);
				}
			}
			i++;
		}
		i = 0;
		j++;
	}
}
