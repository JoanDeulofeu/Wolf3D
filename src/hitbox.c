#include "wolf3d.h"
// int		ft_hitbox2(t_s *s, int key)

int		ft_hitbox(t_s *s, int key)
{
	int		x;
	int		y;
	int		x2;
	int		y2;

	y = s->pos->floaty / SPACE;
	y2 = (s->pos->floaty + SPACE / 4) / SPACE;
	x = s->pos->floatx / SPACE;
	x2 = (s->pos->floatx + SPACE / 4) / SPACE;
	if (s->map[x][y]->envi > 1001 || s->map[x][y2]->envi > 1001 ||
	s->map[x2][y]->envi > 1001 || s->map[x2][y2]->envi > 1001)
			return (0);
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

void	ft_change_dir(t_s *s, int i)
{
	if (i == 2)
	{
		if (s->pos->dirplayer < 180)
			s->pos->dirplayer += 180;
		else
			s->pos->dirplayer -= 180;
	}
	if (i == 4)
	{
		if (s->pos->dirplayer < 90)
			s->pos->dirplayer += 270;
		else
			s->pos->dirplayer -= 90;
	}
	if (i == 3)
	{
		if (s->pos->dirplayer > 270)
			s->pos->dirplayer -= 270;
		else
			s->pos->dirplayer += 90;
	}
	s->pos->tp = 0;
}
