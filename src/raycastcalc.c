#include "wolf3d.h"


void	ft_dir_raycasting1(t_s *s, float angle, float angle2)
{
	int		x;
	int		y;
	int 	stop = 0;
	y = s->pos->moovey / SPACE;
	x = s->pos->moovex / SPACE;
	while(1) // avance dans les x;
	{
		if (s->map[x][y]->envi == 1001 && (s->pos->moovex - SPACE / 2) < x * SPACE)
		{
			s->ray->intx = x * SPACE + SPACE / 2;
			stop = 1;
		}
		else
		{
			x++;
			s->ray->intx = x  * SPACE; //valide par jojo
		}
		s->ray->diffxx = s->ray->intx - s->pos->moovex; //valide par jojo
		s->ray->diffyx = tan(angle) * s->ray->diffxx;
		s->ray->inty = s->pos->moovey - s->ray->diffyx;
		y = s->ray->inty / SPACE;
		s->ray->save1 = sqrtf(powf(s->ray->diffxx,2)+powf(s->ray->diffyx,2));
		if (x >= s->width || y >= s->high || y < 0 || x < 0)
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
		if (s->map[x][y]->envi == 1000 && (s->pos->moovey - SPACE / 2) > y * SPACE)
		{
			s->ray->inty = y * SPACE + SPACE / 2;
			stop = 1;
		}
		else
			s->ray->inty = y * SPACE; //valide par jojo
		s->ray->diffyy = s->pos->moovey - s->ray->inty; //valide par jojo
		s->ray->diffxy = tan(angle2) * s->ray->diffyy;
		s->ray->intx = s->pos->moovex + s->ray->diffxy;
		x = s->ray->intx / SPACE;
		s->ray->save2 = sqrtf(powf(s->ray->diffxy,2)+powf(s->ray->diffyy,2));
		if (x >= s->width || y >= s->high|| y < 0 || x < 0)
			break;
		if (s->map[x][y-1]->envi > 1049)
			break;
		y--;
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
		s->ray->diffxx = s->ray->intx - s->pos->moovex; //valide par jojo
		s->ray->diffyx = tan(angle) * s->ray->diffxx;
		s->ray->inty = s->pos->moovey + s->ray->diffyx;
		y = s->ray->inty / SPACE;
		s->ray->save1 = sqrtf(powf(s->ray->diffxx,2)+powf(s->ray->diffyx,2));
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
		s->ray->diffyy = s->ray->inty - s->pos->moovey; //valide par jojo
		s->ray->diffxy = tan(angle2) * s->ray->diffyy;
		s->ray->intx = s->pos->moovex + s->ray->diffxy;
		x = s->ray->intx / SPACE;
		s->ray->save2 = sqrtf(powf(s->ray->diffxy,2)+powf(s->ray->diffyy,2));
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
		s->ray->diffxx = s->pos->moovex - s->ray->intx; //valide par jojo
		s->ray->diffyx = tan(angle) * s->ray->diffxx;
		s->ray->inty = s->pos->moovey + s->ray->diffyx;
		y = s->ray->inty / SPACE;
		s->ray->save1 = sqrtf(powf(s->ray->diffxx,2)+powf(s->ray->diffyx,2));
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
		s->ray->diffyy = s->ray->inty - s->pos->moovey; //valide par jojo
		s->ray->diffxy = tan(angle2) * s->ray->diffyy;
		s->ray->intx = s->pos->moovex - s->ray->diffxy;
		x = s->ray->intx / SPACE;
		s->ray->save2 = sqrtf(powf(s->ray->diffxy,2)+powf(s->ray->diffyy,2));
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
	y = s->pos->moovey / SPACE;
	x = s->pos->moovex / SPACE;

	while(1) // recule dans les x;
	{
		if (s->map[x][y]->envi == 1001 && (s->pos->moovex - SPACE / 2) > x * SPACE)
		{	s->ray->intx = x * SPACE + SPACE / 2;
				stop = 1;
		}
		else
			s->ray->intx = x  * SPACE; //valide par jojo
		s->ray->diffxx = s->pos->moovex - s->ray->intx; //valide par jojo
		s->ray->diffyx = tan(angle) * s->ray->diffxx;
		s->ray->inty = s->pos->moovey - s->ray->diffyx;
		y = s->ray->inty / SPACE;
		s->ray->save1 = sqrtf(powf(s->ray->diffxx,2)+powf(s->ray->diffyx,2));
		if (y >= s->width || x >= s->high || y < 0 || x < 0)
			break;
		if (s->map[x-1][y]->envi > 1049)
			break;
		x--;
		if (stop == 1)
			break;
	}
	y = s->pos->moovey / SPACE;
	x = s->pos->moovex / SPACE;
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
		s->ray->diffyy = s->pos->moovey - s->ray->inty; //valide par jojo
		s->ray->diffxy = tan(angle2) * s->ray->diffyy;
		s->ray->intx = s->pos->moovex - s->ray->diffxy;
		x = s->ray->intx / SPACE;
		s->ray->save2 = sqrtf(powf(s->ray->diffxy,2)+powf(s->ray->diffyy,2));
		if (x >= s->width || y >= s->high || y < 0 || x < 0)
			break;
		if (s->map[x][y - 1]->envi > 1049)
			break;
		y--;
		if (stop == 1)
			break;
	}
}
