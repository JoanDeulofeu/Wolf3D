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
			s->pos->doorx = 1;
		}
		else
		{
			x++;
			s->ray->intx = x  * SPACE; //valide par jojo
		}
		s->ray->diffx = s->ray->intx - s->pos->moovex; //valide par jojo
		// printf("moovex=%f     diffx= %f   \n", s->pos->moovex , s->ray->diffx);
		s->ray->diffy = tan(angle) * s->ray->diffx;
		s->ray->inty = s->pos->moovey - s->ray->diffy;
		y = s->ray->inty / SPACE;
		s->ray->save1 = sqrtf(powf(s->ray->diffx,2)+powf(s->ray->diffy,2));
		if (x >= s->width || y >= s->high || y < 0 || x < 0)
			break;
		if (s->map[x][y]->envi > 1001)
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
			s->ray->inty2 = y * SPACE + SPACE / 2;
			stop = 1;
			s->pos->doory = 1;
		}
		else
			s->ray->inty2 = y * SPACE; //valide par jojo
		s->ray->diffy = s->pos->moovey - s->ray->inty2; //valide par jojo
		s->ray->diffx = tan(angle2) * s->ray->diffy;
		s->ray->intx2 = s->pos->moovex + s->ray->diffx;
		x = s->ray->intx2 / SPACE;
		s->ray->save2 = sqrtf(powf(s->ray->diffx,2)+powf(s->ray->diffy,2));
		if (x >= s->width || y >= s->high|| y < 0 || x < 0)
			break;
		if (s->map[x][y-1]->envi > 1001)
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
			s->pos->doorx = 1;
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
		if (s->map[x][y]->envi > 1001)
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
			s->ray->inty2 = y * SPACE + SPACE / 2;
			stop = 1;
			s->pos->doory = 1;
		}
		else
		{
		y++;
		s->ray->inty2 = y * SPACE; //valide par jojo
		}
		s->ray->diffy = s->ray->inty2 - s->pos->moovey; //valide par jojo
		s->ray->diffx = tan(angle2) * s->ray->diffy;
		s->ray->intx2 = s->pos->moovex + s->ray->diffx;
		x = s->ray->intx2 / SPACE;
		s->ray->save2 = sqrtf(powf(s->ray->diffx,2)+powf(s->ray->diffy,2));
		if (y >= s->width  || x >= s->high || y < 0 || x < 0)
			break;
		if (s->map[x][y]->envi > 1001)
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
				s->pos->doorx = 1;
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
		if (s->map[x - 1][y]->envi > 1001)
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
			s->ray->inty2 = y * SPACE + SPACE / 2;
			stop = 1;
			s->pos->doory = 1;
		}
		else
		{
		y++;
		s->ray->inty2 = y * SPACE; //valide par jojo
		}
		s->ray->diffy = s->ray->inty2 - s->pos->moovey; //valide par jojo
		s->ray->diffx = tan(angle2) * s->ray->diffy;
		s->ray->intx2 = s->pos->moovex - s->ray->diffx;
		x = s->ray->intx2 / SPACE;
		s->ray->save2 = sqrtf(powf(s->ray->diffx,2)+powf(s->ray->diffy,2));
		if (y >= s->width || x >= s->high || y <= 0 || x <= 0)
			break;
		if (s->map[x][y]->envi > 1001)
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
				s->pos->doorx = 1;
		}
		else
			s->ray->intx = x  * SPACE; //valide par jojo
		s->ray->diffx = s->pos->moovex - s->ray->intx; //valide par jojo
		s->ray->diffy = tan(angle) * s->ray->diffx;
		s->ray->inty = s->pos->moovey - s->ray->diffy;
		y = s->ray->inty / SPACE;
		s->ray->save1 = sqrtf(powf(s->ray->diffx,2)+powf(s->ray->diffy,2));
		if (y >= s->width || x >= s->high || y < 0 || x < 0)
			break;
		if (s->map[x-1][y]->envi > 1001)
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
			s->ray->inty2 = y * SPACE + SPACE / 2;
			stop = 1;
			s->pos->doory = 1;
		}
		else
			s->ray->inty2 = y * SPACE; //valide par jojo
		s->ray->diffy = s->pos->moovey - s->ray->inty2; //valide par jojo
		s->ray->diffx = tan(angle2) * s->ray->diffy;
		s->ray->intx2 = s->pos->moovex - s->ray->diffx;
		x = s->ray->intx2 / SPACE;
		s->ray->save2 = sqrtf(powf(s->ray->diffx,2)+powf(s->ray->diffy,2));
		if (x >= s->width || y >= s->high || y < 0 || x < 0)
			break;
		if (s->map[x][y - 1]->envi > 1001)
			break;
		y--;
		if (stop == 1)
			break;
	}
}
