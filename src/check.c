#include "wolf3d.h"

void	ft_check(t_s *s, char *av)
{
	int		fd;
	int		i;
	char	*line;
	int		width;

	fd = open(av, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		width = 0;
		i = -1;
		s->high++;
		while (line[++i] != '\0')
		{
			if (line[i] != ',' && line[i] != ' ' && line[i] != '\n' &&
				(line[i] < 48 && line[i] > 57))
				ft_usage(2);
			if (line[i] == ',')
				width += 1;
		}
		if (s->high == 1)
			s->width = width / 4;
		if ((width / 4) != s->width)
			ft_usage(2);
		ft_memdel((void **)&line);
	}
	// if (s->high != s->width)
	// 	ft_usage(2);
}

void	ft_check_post_pars(t_s *s)
{
	int x;
	int y;
	int player;

	player = 0;
	x = 0;
	y = 0;
	while (x < s->high)
	{
		while (y < s->width)
		{
			if (s->map[x][y]->envi < 1 || s->map[x][y]->envi > 1999)
				ft_usage(2);
			if (s->map[x][y]->envi == 1000 && (s->map[x+1][y]->envi < 1002 ||
			s->map[x-1][y]->envi < 1002))
				ft_usage(2);
			if (s->map[x][y]->envi == 1001 && (s->map[x][y+1]->envi < 1002 ||
			s->map[x][y-1]->envi < 1002))
				ft_usage(2);
			if (s->map[x][y]->envi_sz < 1 || s->map[x][y]->envi_sz > 5)
				ft_usage(2);
			if (s->map[x][y]->roof < 1 || s->map[x][y]->roof > 999)
				ft_usage(2);
			if (s->map[x][y]->roof_sz < 1 || s->map[x][y]->roof_sz > 5)
				ft_usage(2);
			if (s->map[x][y]->item < 1 || s->map[x][y]->item > 99)
				ft_usage(2);
			if ((x == 0 || x == s->high - 1) && s->map[x][y]->envi < 1000)
				ft_usage(4);
			if ((y == 0 || y == s->width - 1) && s->map[x][y]->envi < 1000)
				ft_usage(4);
			if (s->map[x][y]->item > 1 && s->map[x][y]->item < 6)
				player++;
			y++;
		}
		y = 0;
		x++;
	}
	if (player != 1)
		ft_usage(3);
}
