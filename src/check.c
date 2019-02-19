#include "wolf3d.h"

void	ft_check(t_s *s, char *av)
{
	int		fd;
	int		i;
	char	*line;
	int		width;

	fd = open(av[1], O_RDONLY);
	i = -1;
	width = 0;
	while (get_next_line(fd, &line)) //tant que le fichier est pas fini
	{
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
		ft_memdel((void **)line);
	}
}
