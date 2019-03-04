#include "wolf3d.h"

int		ft_hitbox(t_s *s, int key)
{
	int		x;
	int		y;
	int		x2;
	int		y2;

	y = s->pos->floaty / SPACE;
	y2 = (s->pos->floaty + SPACE / 4) / SPACE ;
	x = s->pos->floatx / SPACE;//trouver la case
	x2 = (s->pos->floatx + SPACE / 4) / SPACE ;
	// printf("\033[33m%d > %d\033[0m\n", s->pos->floaty - 8, x * SPACE);
	if (key == 4) // gauche
	{
		if ((s->pos->floatx - 1 ) < (x * SPACE) && s->map[x-1][y]->envi > 1049)
			{
				if (s->map[x - 1][y]->envi < 1100)
					ft_swap_pos(s, 4, x - 1, y);
				return (0);
			}
		if ((s->pos->floatx - 1 ) < (x * SPACE) && s->map[x-1][y2]->envi > 1049)
		{
			if (s->map[x - 1][y2]->envi < 1100)
				ft_swap_pos(s, 4, x - 1, y2);
			return (0);
		}
		if (s->pos->floatx > x * SPACE + SPACE / 2) // portehorizontale
		{
		if ((s->pos->floatx - 1 ) < (x * SPACE + SPACE / 2) && s->map[x][y]->envi == 1001)
			return (0);
		if ((s->pos->floatx - 1 ) < (x * SPACE + SPACE / 2) && s->map[x][y2]->envi == 1001)
			return (0);
		}
	}
	if (key == 3) // droite
	{
		if ((s->pos->floatx + SPACE / 4) > ((x + 1) * SPACE) && s->map[x+1][y]->envi > 1049)
		{
			if (s->map[x + 1][y]->envi < 1100)
				ft_swap_pos(s, 3, x + 1, y);
			return (0);
		}
		if ((s->pos->floatx + SPACE / 4) > ((x + 1) * SPACE) && s->map[x+1][y2]->envi > 1049)
		{
			if (s->map[x + 1][y2]->envi < 1100)
				ft_swap_pos(s, 3, x + 1, y2);
			return (0);
		}
		if (s->pos->floatx < x * SPACE + SPACE / 2) // portehorizontale
		{
		if ((s->pos->floatx + SPACE / 4) > ((x) * SPACE + SPACE / 2) && s->map[x][y]->envi == 1001)
			return (0);
		if ((s->pos->floatx + SPACE / 4) > ((x) * SPACE + SPACE / 2) && s->map[x][y2]->envi == 1001)
			return (0);
		}
	}
	if (key == 1) //haut
	{
		if ((s->pos->floaty - 1) < (y * SPACE) && s->map[x][y - 1]->envi > 1049)
		{
			// printf("test2");
			if (s->map[x][y - 1]->envi < 1100)
			{
				// printf("test3");
				ft_swap_pos(s, 1, x, y -1);
			}
			return (0);
		}
		if ((s->pos->floaty - 1) < (y * SPACE) && s->map[x2][y - 1]->envi > 1049)
		{
			// printf("test2");
			if (s->map[x2][y - 1]->envi < 1100)
			{
				// printf("test3");
				ft_swap_pos(s, 1, x2, y - 1);
			}
			return (0);
		}
		if (s->pos->floaty > y * SPACE + SPACE / 2) // porteverticale
		{
		if ((s->pos->floaty - 1) < (y * SPACE + SPACE / 2 ) && s->map[x][y]->envi == 1000)
			return (0);
		if ((s->pos->floaty - 1) < (y * SPACE + SPACE / 2) && s->map[x2][y2]->envi == 1000)
			return (0);
		}
	}
	if (key == 2) // bas
	{
		if ((s->pos->floaty + SPACE / 4) > ((y + 1) * SPACE) && s->map[x][y + 1]->envi > 1049)
		{
				printf("test1");
			if (s->map[x][y + 1]->envi < 1100)
			{
				printf("test3");
				ft_swap_pos(s, 2, x, y + 1);
			}
			return (0);
		}
		if ((s->pos->floaty + SPACE / 4) > ((y + 1) * SPACE) && s->map[x2][y + 1]->envi > 1049)
		{	printf("test2");
			if (s->map[x2][y + 1]->envi < 1100)
			{
				printf("test3");
				ft_swap_pos(s, 2, x2, y + 1 );
			}
			return (0);
		}
		if (s->pos->floaty < y * SPACE + SPACE / 2) // porteverticale
		{
			if ((s->pos->floaty + SPACE / 4) > ((y) * SPACE + SPACE / 2 ) && s->map[x][y]->envi == 1000)
				return (0);
			if ((s->pos->floaty + SPACE / 4) > ((y ) * SPACE + SPACE / 2 ) && s->map[x2][y]->envi == 1000)
				return (0);

		}
	}

	// printf("\033[32mYOU CAN MOVE\033[0m\n");
	return (1);
}

void ft_swap_pos(t_s *s, int mode, int x, int y)
{
	int i = 0;
	int j = 0;
	int tp;
	int diffx;
	int diffy;
	tp = s->map[x][y]->envi;
	if (mode == 1) // w
	{
	while (j < s->high)
	{
		while (i < s->width)
		{
			if (i != x && j != y)
			{
				if (s->map[i][j]->envi == tp)
				{
					diffx = x - i;
					diffy = y - j + 1;
					s->pos->posplayer.x -= (diffx * SPACE) ;
					s->pos->posplayer.y -= (diffy * SPACE)+SPACE/4 ;
					s->pos->floatx -= (diffx * SPACE) ;
					s->pos->floaty -= (diffy * SPACE)+SPACE/4 ;
				}
			}
			i++;
		}
		i = 0;
		j++;
	}
}
	if (mode == 2) //s
	{
	while (j < s->high)
	{
		while (i < s->width)
		{
			if (i != x && j != y)
			{
				if (s->map[i][j]->envi == tp)
				{
					diffx = x - i;
					diffy = y - j -1;
					s->pos->posplayer.x -= (diffx * SPACE) ;
					s->pos->posplayer.y -= (diffy * SPACE)-SPACE/4 ;
					s->pos->floatx -= (diffx * SPACE) ;
					s->pos->floaty -= (diffy * SPACE)-SPACE/4 ;
				}
			}
			i++;
		}
		i = 0;
		j++;
	}
	}
	if (mode == 3) //q
	{
		while (j < s->high)
		{
			while (i < s->width)
			{
				if (i != x && j != y)
				{
					if (s->map[i][j]->envi == tp)
					{
						diffx = x - i + 1;
						diffy = y - j;
						s->pos->posplayer.x -= (diffx * SPACE) ;
						s->pos->posplayer.y -= (diffy * SPACE)-SPACE/4 ;
						s->pos->floatx -= (diffx * SPACE) ;
						s->pos->floaty -= (diffy * SPACE)-SPACE/4 ;
					}
				}
				i++;
			}
			i = 0;
			j++;
		}
	}
	if (mode == 4) //d
	{
		while (j < s->high)
		{
			while (i < s->width)
			{
				if (i != x && j != y)
				{
					if (s->map[i][j]->envi == tp)
					{
						diffx = x - i - 1;
						diffy = y - j;
						s->pos->posplayer.x -= (diffx * SPACE) ;
						s->pos->posplayer.y -= (diffy * SPACE)-SPACE/4 ;
						s->pos->floatx -= (diffx * SPACE) ;
						s->pos->floaty -= (diffy * SPACE)-SPACE/4 ;
					}
				}
				i++;
			}
			i = 0;
			j++;
		}
	}
}


void ft_dir_player(t_s *s, int i)
{
	int tmp;
	tmp = s->pos->dirplayer;
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
	if (s->pos->dirplayer <= 90)
	{
		if(ft_hitbox(s,1))
		{
		s->pos->floaty -= (1-(s->pos->dirplayer/90));
		if (s->pos->floaty < s->pos->posplayer.y - 0.5)
			s->pos->posplayer.y --;
		}
		if(ft_hitbox(s,3))
		{
		s->pos->floatx += (s->pos->dirplayer/90);
		if (s->pos->floatx > s->pos->posplayer.x + 0.5)
			s->pos->posplayer.x ++;
		}
	}
	if (s->pos->dirplayer > 90 && s->pos->dirplayer <= 180)
	{
		if(ft_hitbox(s,2))
		{
		s->pos->floaty += ((s->pos->dirplayer-90)/90);
		if (s->pos->floaty > s->pos->posplayer.y + 0.5 )
			s->pos->posplayer.y ++;
		}
		if(ft_hitbox(s,3))
		{
		s->pos->floatx += (1-((s->pos->dirplayer-90)/90));
		if (s->pos->floatx > s->pos->posplayer.x + 0.5 )
			s->pos->posplayer.x ++;
		}
	}
	if (s->pos->dirplayer > 180 && s->pos->dirplayer <= 270)
	{
		if(ft_hitbox(s,2))
		{
		s->pos->floaty += (1-((s->pos->dirplayer-180)/90));
		if (s->pos->floaty > s->pos->posplayer.y + 0.5 )
			s->pos->posplayer.y ++;
		}
		if(ft_hitbox(s,4))
		{
		s->pos->floatx -= ((s->pos->dirplayer-180)/90);
		if (s->pos->floatx < s->pos->posplayer.x - 0.5 )
			s->pos->posplayer.x --;
		}
	}
	if (s->pos->dirplayer > 270 && s->pos->dirplayer <= 360)
	{
		if(ft_hitbox(s,1))
		{
		s->pos->floaty -= ((s->pos->dirplayer-270)/90);
		if (s->pos->floaty < s->pos->posplayer.y - 0.5 )
			s->pos->posplayer.y --;
		}
		if(ft_hitbox(s,4))
		{
		s->pos->floatx -= (1-((s->pos->dirplayer-270)/90));
		if (s->pos->floatx < s->pos->posplayer.x - 0.5)
			s->pos->posplayer.x --;
		}
	}
	s->pos->dirplayer = tmp;
	s->pos->xplayer = s->pos->posplayer.x + SPACE / 8;
	s->pos->yplayer = s->pos->posplayer.y + SPACE / 8;
}
