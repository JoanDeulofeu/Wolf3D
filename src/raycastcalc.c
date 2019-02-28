#include "wolf3d.h"


void	ft_dir_raycasting1(t_s *s, float angle, float angle2)
{
	int		x;
	int		y;

	y = s->pos->moovey / SPACE;
	x = s->pos->moovex / SPACE;
	while(1) // avance dans les x;
	{
		x++;
		s->ray->intx = x  * SPACE; //valide par jojo
		s->ray->diffx = s->ray->intx - s->pos->moovex; //valide par jojo
		s->ray->diffy = tan(angle) * s->ray->diffx;
		s->ray->inty = s->pos->moovey - s->ray->diffy;
		y = s->ray->inty / SPACE;
		s->ray->save1 = sqrtf(powf(s->ray->diffx,2)+powf(s->ray->diffy,2));
		if (x >= s->width || y >= s->high || y < 0 || x < 0)
			break;
		if (s->map[x][y]->envi > 999)
			break;
	}
	y = s->pos->moovey / SPACE;
	x = s->pos->moovex / SPACE;
	while(1)
	{
		s->ray->inty = y * SPACE; //valide par jojo
		s->ray->diffy = s->pos->moovey - s->ray->inty; //valide par jojo
		s->ray->diffx = tan(angle2) * s->ray->diffy;
		s->ray->intx = s->pos->moovex + s->ray->diffx;
		x = s->ray->intx / SPACE;
		s->ray->save2 = sqrtf(powf(s->ray->diffx,2)+powf(s->ray->diffy,2));
		if (x >= s->width || y >= s->high|| y < 0 || x < 0)
			break;
		if (s->map[x][y-1]->envi > 999)
			break;
		y--;
	}
}

void	ft_dir_raycasting2(t_s *s, float angle, float angle2)
{
	int		x;
	int		y;

	y = s->pos->moovey / SPACE;
	x = s->pos->moovex / SPACE;
	while(1) // avance dans les x;
	{
		x++;
		s->ray->intx = x  * SPACE; //valide par jojo
		s->ray->diffx = s->ray->intx - s->pos->moovex; //valide par jojo
		s->ray->diffy = tan(angle) * s->ray->diffx;
		s->ray->inty = s->pos->moovey + s->ray->diffy;
		y = s->ray->inty / SPACE;
		s->ray->save1 = sqrtf(powf(s->ray->diffx,2)+powf(s->ray->diffy,2));
		if (y >= s->width || x >= s->high   || y < 0 || x < 0)
			break;
		if (s->map[x][y]->envi > 999)
			break;
	}
	y = s->pos->moovey / SPACE;
	x = s->pos->moovex / SPACE;
	while(1)
	{
		y++;
		s->ray->inty = y * SPACE; //valide par jojo
		s->ray->diffy = s->ray->inty - s->pos->moovey; //valide par jojo
		s->ray->diffx = tan(angle2) * s->ray->diffy;
		s->ray->intx = s->pos->moovex + s->ray->diffx;
		x = s->ray->intx / SPACE;
		s->ray->save2 = sqrtf(powf(s->ray->diffx,2)+powf(s->ray->diffy,2));
		if (y >= s->width  || x >= s->high || y < 0 || x < 0)
			break;
		if (s->map[x][y]->envi > 999)
			break;
	}
}

void	ft_dir_raycasting3(t_s *s, float angle, float angle2)
{
	int		x;
	int		y;

	y = s->pos->moovey / SPACE;
	x = s->pos->moovex / SPACE;


	while(1) // avance dans les x;
	{
		s->ray->intx = x  * SPACE; //valide par jojo
		s->ray->diffx = s->pos->moovex - s->ray->intx; //valide par jojo
		s->ray->diffy = tan(angle) * s->ray->diffx;
		s->ray->inty = s->pos->moovey + s->ray->diffy;
		y = s->ray->inty / SPACE;
		s->ray->save1 = sqrtf(powf(s->ray->diffx,2)+powf(s->ray->diffy,2));
		if (y >= s->width || x >= s->high || y <= 0 || x <= 0)
			break;
		if (s->map[x - 1][y]->envi > 999)
			break;
		x--;
	}
	y = s->pos->moovey / SPACE;
	x = s->pos->moovex / SPACE;
	
	while(1)
	{
		y++;
		s->ray->inty = y * SPACE; //valide par jojo
		s->ray->diffy = s->ray->inty - s->pos->moovey; //valide par jojo
		s->ray->diffx = tan(angle2) * s->ray->diffy;
		s->ray->intx = s->pos->moovex - s->ray->diffx;
		x = s->ray->intx / SPACE;
		s->ray->save2 = sqrtf(powf(s->ray->diffx,2)+powf(s->ray->diffy,2));
		if (y >= s->width || x >= s->high || y <= 0 || x <= 0)
			break;
		if (s->map[x][y]->envi > 999)
			break;
	}

}
void	ft_dir_raycasting4(t_s *s, float angle, float angle2)
{
	int		x;
	int		y;
	y = s->pos->moovey / SPACE;
	x = s->pos->moovex / SPACE;

	while(1) // recule dans les x;
	{
		s->ray->intx = x  * SPACE; //valide par jojo
		s->ray->diffx = s->pos->moovex - s->ray->intx; //valide par jojo
		s->ray->diffy = tan(angle) * s->ray->diffx;
		s->ray->inty = s->pos->moovey - s->ray->diffy;
		y = s->ray->inty / SPACE;
		s->ray->save1 = sqrtf(powf(s->ray->diffx,2)+powf(s->ray->diffy,2));
		if (y >= s->width || x >= s->high || y < 0 || x < 0)
			break;
		if (s->map[x-1][y]->envi > 999)
			break;
		x--;
	}
	y = s->pos->moovey / SPACE;
	x = s->pos->moovex / SPACE;
	while(1)
	{
		s->ray->inty = y * SPACE; //valide par jojo
		s->ray->diffy = s->pos->moovey - s->ray->inty; //valide par jojo
		s->ray->diffx = tan(angle2) * s->ray->diffy;
		s->ray->intx = s->pos->moovex - s->ray->diffx;
		x = s->ray->intx / SPACE;
		s->ray->save2 = sqrtf(powf(s->ray->diffx,2)+powf(s->ray->diffy,2));
		if (x >= s->width || y >= s->high || y < 0 || x < 0)
			break;
		if (s->map[x][y - 1]->envi > 999)
			break;
		y--;
	}
}
