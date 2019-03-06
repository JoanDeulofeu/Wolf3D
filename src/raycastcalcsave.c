#include "wolf3d.h"

void	ft_dir_raycasting1(t_s *s, float angle, float angle2)
{
	int		x;
	int		y;
	int		xsave;
	int 	ysave;
	int 	stop = 0;
	s->ray->recursx = 0;
	s->ray->recursy = 0;
	y = s->pos->moovey / SPACE;
	x = s->pos->moovex / SPACE;
	xsave = x;
	ysave = y;
	while(1) // avance dans les x;
	{
		if (s->map[x][y]->envi == 1001 && (s->pos->moovex - SPACE / 2) < x * SPACE)
		{	s->ray->intx = x * SPACE + SPACE / 2;
			stop = 1;
		}
		else
		{
		x++;
		s->ray->intx = x  * SPACE; //valide par jojo
		}
		s->ray->diffx = s->ray->intx - s->pos->moovex; //valide par jojo
		s->ray->diffy = tan(angle) * s->ray->diffx;
		s->ray->inty = s->pos->moovey - s->ray->diffy;
		y = s->ray->inty / SPACE;
		s->ray->save1 = sqrtf(powf(s->ray->diffx,2)+powf(s->ray->diffy,2))+ s->ray->swap1;
		if (x >= s->width || y >= s->high || y < 0 || x < 0)
			break;
		if (s->map[x][y]->envi > 1049)
			{
				if (s->map[x][y]->envi < 1100)
				{
					s->ray->swap1 = s->ray->save1;
					s->ray->recursx = 1;
					ft_swap_ray(s, 1, x, y);
				}
			break;
			}
		if (stop == 1)
			break;
	}
	y = ysave;
	x = xsave;
	stop = 0;
	while(1)
	{
		if (s->map[x][y]->envi == 1000 && (s->pos->moovey - SPACE / 2) > y * SPACE)
		{
			s->ray->inty = y * SPACE + SPACE / 2;
			stop = 1;
		}
		else
			s->ray->inty = y * SPACE; //valide par jojo
		s->ray->diffy = s->pos->moovey - s->ray->inty; //valide par jojo
		s->ray->diffx = tan(angle2) * s->ray->diffy;
		s->ray->intx = s->pos->moovex + s->ray->diffx;
		x = s->ray->intx / SPACE;
		s->ray->save2 = sqrtf(powf(s->ray->diffx,2)+powf(s->ray->diffy,2))+ s->ray->swap2;
		if (x >= s->width || y >= s->high|| y < 0 || x < 0)
			break;
		y--;
		if (s->map[x][y]->envi > 1049)
		{
			if (s->map[x][y]->envi < 1100)
			{
				s->ray->recursy = 1;
				s->ray->swap2 = s->ray->save2;
				ft_swap_ray(s, 11, x, y );
			}
			break;
		}
		if (stop == 1)
			break;
	}
}

void	ft_dir_raycasting2(t_s *s, float angle, float angle2)
{
	int		x;
	int		y;
	int 	stop = 0;
	y = s->pos->moovey / SPACE;
	x = s->pos->moovex / SPACE;
	while(1) // avance dans les x;
	{
		if (s->map[x][y]->envi == 1001 && (s->pos->moovex - SPACE / 2) < x * SPACE)
		{	s->ray->intx = x * SPACE + SPACE / 2;
			stop = 1;
		}
		else
		{
		x++;
		s->ray->intx = x * SPACE; //valide par jojo
		}
		s->ray->diffx = s->ray->intx - s->pos->moovex; //valide par jojo
		s->ray->diffy = tan(angle) * s->ray->diffx;
		s->ray->inty = s->pos->moovey + s->ray->diffy;
		y = s->ray->inty / SPACE;
		s->ray->save1 = sqrtf(powf(s->ray->diffx,2)+powf(s->ray->diffy,2));
		if (y >= s->width || x >= s->high   || y < 0 || x < 0)
			break;
		if (s->map[x][y]->envi > 1049)
			break;
		if (stop == 1)
			break;
	}
	y = s->pos->moovey / SPACE;
	x = s->pos->moovex / SPACE;
	stop = 0;
	while(1)
	{
		if (s->map[x][y]->envi == 1000 && (s->pos->moovey - SPACE / 2) < y * SPACE)
		{
			s->ray->inty = y * SPACE + SPACE / 2;
			stop = 1;
		}
		else
		{
		y++;
		s->ray->inty = y * SPACE; //valide par jojo
		}
		s->ray->diffy = s->ray->inty - s->pos->moovey; //valide par jojo
		s->ray->diffx = tan(angle2) * s->ray->diffy;
		s->ray->intx = s->pos->moovex + s->ray->diffx;
		x = s->ray->intx / SPACE;
		s->ray->save2 = sqrtf(powf(s->ray->diffx,2)+powf(s->ray->diffy,2));
		if (y >= s->width  || x >= s->high || y < 0 || x < 0)
			break;
		if (s->map[x][y]->envi > 1049)
			break;
		if (stop == 1)
			break;
	}
}

void	ft_dir_raycasting3(t_s *s, float angle, float angle2)
{
	int		x;
	int		y;
	int 	stop = 0;
	y = s->pos->moovey / SPACE;
	x = s->pos->moovex / SPACE;


	while(1) // avance dans les x;
	{
		if (s->map[x][y]->envi == 1001 && (s->pos->moovex - SPACE / 2) > x * SPACE)
		{	s->ray->intx = x * SPACE + SPACE / 2;
				stop = 1;
		}
		else
			s->ray->intx = x  * SPACE; //valide par jojo
		s->ray->diffx = s->pos->moovex - s->ray->intx; //valide par jojo
		s->ray->diffy = tan(angle) * s->ray->diffx;
		s->ray->inty = s->pos->moovey + s->ray->diffy;
		y = s->ray->inty / SPACE;
		s->ray->save1 = sqrtf(powf(s->ray->diffx,2)+powf(s->ray->diffy,2));
		if (y >= s->width || x >= s->high || y <= 0 || x <= 0)
			break;
		if (s->map[x - 1][y]->envi > 1049)
			break;
		x--;
		if (stop == 1)
			break;
	}
	stop = 0;
	y = s->pos->moovey / SPACE;
	x = s->pos->moovex / SPACE;

	while(1)
	{
		if (s->map[x][y]->envi == 1000 && (s->pos->moovey - SPACE / 2) < y * SPACE)
		{
			s->ray->inty = y * SPACE + SPACE / 2;
			stop = 1;
		}
		else
		{
		y++;
		s->ray->inty = y * SPACE; //valide par jojo
		}
		s->ray->diffy = s->ray->inty - s->pos->moovey; //valide par jojo
		s->ray->diffx = tan(angle2) * s->ray->diffy;
		s->ray->intx = s->pos->moovex - s->ray->diffx;
		x = s->ray->intx / SPACE;
		s->ray->save2 = sqrtf(powf(s->ray->diffx,2)+powf(s->ray->diffy,2));
		if (y >= s->width || x >= s->high || y <= 0 || x <= 0)
			break;
		if (s->map[x][y]->envi > 1049)
			break;
		if (stop == 1)
			break;
	}

}
void	ft_dir_raycasting4(t_s *s, float angle, float angle2)
{
	int		x;
	int		y;
	int 	stop = 0;
	int		xsave;
	int 	ysave;
	y = s->pos->moovey / SPACE;
	x = s->pos->moovex / SPACE;
	s->ray->recursx = 0;
	s->ray->recursy = 0;
	xsave = x;
	ysave = y;
	while(1) // recule dans les x;
	{
		if (s->map[x][y]->envi == 1001 && (s->pos->moovex - SPACE / 2) > x * SPACE)
		{	s->ray->intx = x * SPACE + SPACE / 2;
				stop = 1;
		}
		else
			s->ray->intx = x  * SPACE; //valide par jojo
		s->ray->diffx = s->pos->moovex - s->ray->intx; //valide par jojo
		s->ray->diffy = tan(angle) * s->ray->diffx;
		s->ray->inty = s->pos->moovey - s->ray->diffy;
		y = s->ray->inty / SPACE;
		s->ray->save1 = sqrtf(powf(s->ray->diffx,2)+powf(s->ray->diffy,2))+ s->ray->swap1;
		if (y >= s->width || x >= s->high || y < 0 || x < 0)
			break;
		x--;
		if (s->map[x][y]->envi > 1049)
		{
			// if (s->map[x][y]->envi < 1100)
			// {
			// 	s->ray->swap1 = s->ray->save1;
			// 	s->ray->recursx = 1;
			// 	ft_swap_ray(s, 4, x, y);
			// }
			break;
		}
		if (stop == 1)
			break;
	}
	y = ysave;
	x = xsave;
	stop = 0;
	while(1)
	{
		if (s->map[x][y]->envi == 1000 && (s->pos->moovey - SPACE / 2) > y * SPACE)
		{
			s->ray->inty = y * SPACE + SPACE / 2;
			stop = 1;
		}
		else
			s->ray->inty = y * SPACE; //valide par jojo
		s->ray->diffy = s->pos->moovey - s->ray->inty; //valide par jojo
		s->ray->diffx = tan(angle2) * s->ray->diffy;
		s->ray->intx = s->pos->moovex - s->ray->diffx;
		x = s->ray->intx / SPACE;
		s->ray->save2 = sqrtf(powf(s->ray->diffx,2)+powf(s->ray->diffy,2))+ s->ray->swap2;
		if (x >= s->width || y >= s->high || y < 0 || x < 0)
			break;
		y--;
		if (s->map[x][y]->envi > 1049)
		{
			// if (s->map[x][y]->envi < 1100)
			// {
			// 	s->ray->recursy = 1;
			// 	s->ray->swap2 = s->ray->save2;
			// 	ft_swap_ray(s, 44, x, y);
			// }
			break;
		}
		if (stop == 1)
			break;
	}
}

void ft_swap_ray(t_s *s, int mode, int x, int y)
{
	int i = 0;
	int j = 0;
	int tp;
	int diffx;
	int diffy;
	int stop = 0;
	tp = s->map[x][y]->envi;
	if (mode == 1) // w
	{
		while (j < s->high && stop == 0)
		{
			while (i < s->width && stop == 0)
			{
				if (i != x && j != y)
				{
					if (s->map[i][j]->envi == tp)
					{
						diffx = x - i;
						diffy = y - j;
						s->pos->moovex = ((i+1) * SPACE);
						s->pos->moovey -= (diffy * SPACE);
						stop = 1;
						break;
					}
				}
				i++;
			}
			i = 0;
			j++;
		}
	}
	if (mode == 11) // w
	{
		while (j < s->high && stop == 0)
		{
			while (i < s->width && stop == 0)
			{
				if (i != x && j != y)
				{
					if (s->map[i][j]->envi == tp)
					{
						diffx = x - i;
						diffy = y - j;
						s->pos->moovex -= (diffx * SPACE);
						s->pos->moovey = (j * SPACE);
						stop = 1;
						break;
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
		while (j < s->high && stop == 0)
		{
			while (i < s->width && stop == 0)
			{
				if (i != x && j != y)
				{
					if (s->map[i][j]->envi == tp)
					{
						diffx = x - i - 1;
						diffy = y - j;
						s->pos->moovex -= (diffx * SPACE);
						s->pos->moovey -= (diffy * SPACE);
						printf("test");
						stop = 1;
						break;
					}
				}
				i++;
			}
			i = 0;
			j++;
		}
		// ft_dir_raycasting(s);
	}
	if (mode == 22) //s
	{
		while (j < s->high && stop == 0)
		{
			while (i < s->width && stop == 0)
			{
				if (i != x && j != y)
				{
					if (s->map[i][j]->envi == tp)
					{
						diffx = x - i + 1;
						diffy = y - j;
						s->pos->moovex -= (diffx * SPACE);
						s->pos->moovey -= (diffy * SPACE);
						stop = 1;
						break;
					}
				}
				i++;
			}
			i = 0;
			j++;
		}
		// ft_dir_raycasting(s);
	}
	if (mode == 3) //q
	{
		while (j < s->high && stop == 0)
		{
			while (i < s->width && stop == 0)
			{
				if (i != x && j != y)
				{
					if (s->map[i][j]->envi == tp)
					{
						diffx = x - i ;
						diffy = y - j + 1;
						s->pos->moovex -= (diffx * SPACE);
						s->pos->moovey -= (diffy * SPACE);
						stop = 1;
						break;
					}
				}
				i++;
			}
			i = 0;
			j++;
		}
	}
	if (mode == 4) // w
	{
		while (j < s->high && stop == 0)
		{
			while (i < s->width && stop == 0)
			{
				if (i != x && j != y)
				{
					if (s->map[i][j]->envi == tp)
					{
						diffx = x - i;
						diffy = y - j;
						s->pos->moovex = ((i+1) * SPACE);
						s->pos->moovey -= (diffy * SPACE);
						stop = 1;
						break;
					}
				}
				i++;
			}
			i = 0;
			j++;
		}
	}
	if (mode == 44) // w
	{
		while (j < s->high && stop == 0)
		{
			while (i < s->width && stop == 0)
			{
				if (i != x && j != y)
				{
					if (s->map[i][j]->envi == tp)
					{
						diffx = x - i - 1;
						diffy = y - j;
						s->pos->moovex -= (diffx * SPACE);
						s->pos->moovey = (j * SPACE);
						stop = 1;
						break;
					}
				}
				i++;
			}
			i = 0;
			j++;
		}
	}
}
