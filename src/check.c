#include "wolf3d.h"

void	ft_check(t_s *s,char *av)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(av[1], O_RDONLY);
	i = -1;
	while (get_next_line(fd, &line)) //tant que le fichier est pas fini
	{
		s->high++;
		while (line[++i] != '\0')
		{
			if (line[i] != ',' && line[i] != ' ' && line[i] != '\n' &&
				(line[i] < 48 && line[i] > 57))
				ft_usage(2);
			if (line[i++] == ',' && s->high == 1)
				s->width += 1;
		}
		ft_memdel((void **)line);
	}
}
