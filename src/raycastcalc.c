#include "wolf3d.h"


float ft_dir_raycasting1(t_s *s, float angle, float angle2)
{
	float 	diffx;
	float 	diffy;
	int		x;
	int		y;
	float 	inty;
	float 	intx;
	float	save1;
	float	save2;
	// float 	savex;
	// float 	savey;
	// float 	savex2;
	// float 	savey2;

	y = s->pos->moovey / SPACE;
	x = s->pos->moovex / SPACE;

	while(1) // avance dans les x;
	{
		x++;
		intx = x  * SPACE; //valide par jojo
		diffx = intx - s->pos->moovex; //valide par jojo
		diffy = tan(angle) * diffx;
		inty = s->pos->moovey - diffy;
		y = inty / SPACE;
		save1 = sqrtf(powf(diffx,2)+powf(diffy,2));
		if (x >= s->width || y >= s->high || y < 0 || x < 0)
			break;
		if (s->map[x][y]->envi > 999)
			break;
	}
	y = s->pos->moovey / SPACE;
	x = s->pos->moovex / SPACE;
	while(1)
	{
		inty = y * SPACE; //valide par jojo
		diffy = s->pos->moovey - inty; //valide par jojo
		diffx = tan(angle2) * diffy;
		intx = s->pos->moovex + diffx;
		x = intx / SPACE;
		save2 = sqrtf(powf(diffx,2)+powf(diffy,2));
		if (x >= s->width || y >= s->high|| y < 0 || x < 0)
			break;
		if (s->map[x][y-1]->envi > 999)
			break;
		y--;
	}
	if (save1 < save2)
		{
			s->pos->nsew = 4;
			return(save1);
		}
	else
		{
			s->pos->nsew = 3;
			return(save2);
		}
}

float ft_dir_raycasting2(t_s *s, float angle, float angle2)
{
	float 	diffx;
	float 	diffy;
	int		x;
	int		y;
	float 	inty;
	float 	intx;
	float	save1;
	float	save2;

	y = s->pos->moovey / SPACE;
	x = s->pos->moovex / SPACE;
	while(1) // avance dans les x;
	{
		x++;
		intx = x  * SPACE; //valide par jojo
		diffx = intx - s->pos->moovex; //valide par jojo
		diffy = tan(angle) * diffx;
		inty = s->pos->moovey + diffy;
		y = inty / SPACE;
		save1 = sqrtf(powf(diffx,2)+powf(diffy,2));
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
		inty = y * SPACE; //valide par jojo
		diffy = inty - s->pos->moovey; //valide par jojo
		diffx = tan(angle2) * diffy;
		intx = s->pos->moovex + diffx;
		x = intx / SPACE;
		save2 = sqrtf(powf(diffx,2)+powf(diffy,2));
		if (y >= s->width  || x >= s->high || y < 0 || x < 0)
			break;
		if (s->map[x][y]->envi > 999)
			break;
	}
	if (save1 < save2)
		{
			s->pos->nsew = 4;
			return(save1);
			// s->pos->moovey = inty;
			// s->pos->moovex = intx;
		}
	else
		{
			s->pos->nsew = 1;
			return(save2);
			// s->pos->moovey = inty2;
			// s->pos->moovex = intx2;
		}
	// printf("test6\n");
}

float ft_dir_raycasting3(t_s *s, float angle, float angle2)
{
	float 	diffx;
	float 	diffy;
	int		x;
	int		y;
	float 	inty;
	float 	intx;
	float	save1;
	float	save2;

	y = s->pos->moovey / SPACE;
	x = s->pos->moovex / SPACE;


	while(1) // avance dans les x;
	{
		intx = x  * SPACE; //valide par jojo
		diffx = s->pos->moovex - intx; //valide par jojo
		diffy = tan(angle) * diffx;
		inty = s->pos->moovey + diffy;
		y = inty / SPACE;
		save1 = sqrtf(powf(diffx,2)+powf(diffy,2));
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
		inty = y * SPACE; //valide par jojo
		diffy = inty - s->pos->moovey; //valide par jojo
		diffx = tan(angle2) * diffy;
		intx = s->pos->moovex - diffx;
		x = intx / SPACE;
		save2 = sqrtf(powf(diffx,2)+powf(diffy,2));
		if (y >= s->width || x >= s->high || y <= 0 || x <= 0)
			break;
		if (s->map[x][y]->envi > 999)
			break;
	}
	if (save1 < save2)
		{
			s->pos->nsew = 2;
			return(save1);
			// s->pos->moovey = inty;
			// s->pos->moovex = intx;
		}
	else
		{
			s->pos->nsew = 1;
			return(save2);
			// s->pos->moovey = inty2;
			// s->pos->moovex = intx2;
		}
}
float ft_dir_raycasting4(t_s *s, float angle, float angle2)
{
	float 	diffx;
	float 	diffy;
	int		x;
	int		y;
	float 	inty;
	float 	intx;
	float	save1;
	float	save2;
	// float 	savex;
	// float 	savey;
	// float 	savex2;
	// float 	savey2;
	y = s->pos->moovey / SPACE;
	x = s->pos->moovex / SPACE;

	while(1) // recule dans les x;
	{
		intx = x  * SPACE; //valide par jojo
		diffx = s->pos->moovex - intx; //valide par jojo
		diffy = tan(angle) * diffx;
		inty = s->pos->moovey - diffy;
		y = inty / SPACE;
		save1 = sqrtf(powf(diffx,2)+powf(diffy,2));
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
		inty = y * SPACE; //valide par jojo
		diffy = s->pos->moovey - inty; //valide par jojo
		diffx = tan(angle2) * diffy;
		intx = s->pos->moovex - diffx;
		x = intx / SPACE;
		save2 = sqrtf(powf(diffx,2)+powf(diffy,2));
		if (x >= s->width || y >= s->high || y < 0 || x < 0)
			break;
		if (s->map[x][y - 1]->envi > 999)
			break;
		y--;
	}
	if (save1 < save2)
		{
			s->pos->nsew = 2;
			return(save1);
			// s->pos->moovey = inty;
			// s->pos->moovex = intx;
		}
	else
		{
			s->pos->nsew = 3;
			return(save2);
			// s->pos->moovey = inty2;
			// s->pos->moovex = intx2;
		}
}
