#include "wolf3d.h"

void	ft_size_map(t_s *s, char *av) // trouve la taille de la map
{
	int		fd;
	int		i;
	char	*line;

	s->width = 0;
	s->high = 0;
	fd = open(av[1], O_RDONLY);
	i = 0;
	line = NULL;
	if (get_next_line(fd, &line) == 0)
		ft_usage(2);
	else
		s->high++;
	while (line[i] != '\0')
		if (line[i++] == ',')
			s->width += 1;
	s->width /= 4;
	while (get_next_line(fd, &line) != 0) //free line a chaque boucle? #jsp
		s->high++;
	close(fd);
}

char	*ft_tmp_to_char(char *tmp, char c)
{
	while (tmp != c) //avance jusqu'a la virgule
		tmp++;
	tmp++; //puis juste apres la virgule
}

void	ft_parcing(t_s *s, char *av)
{
	int		fd;
	int		i;
	int		u;
	int		x;
	int		y;
	char	*line;
	char	**tab;
	char	*tmp;

	ft_size_map(av[1]);
	fd = open(av[1], O_RDONLY);
	i = 0;
	u = 0;
	x = 0;
	while (get_next_line(fd, &line)) //tant que le fichier est pas fini
	{
		y = 0;
		tab = ft_strsplit(line);
		while (tab[i] != 0) //tant que la ligne est pas fini
		{
			tmp = tab[i][u];
			s->map[x][y]->envi = atoi(tmp);
			tmp = ft_tmp_to_char(tmp, ',');
			s->map[x][y]->envi_sz = atoi(tmp);
			tmp = ft_tmp_to_char(tmp, ',');
			s->map[x][y]->roof = atoi(tmp);
			tmp = ft_tmp_to_char(tmp, ',');
			s->map[x][y]->roof_sz = atoi(tmp);
			tmp = ft_tmp_to_char(tmp, ',');
			s->map[x][y]->item = atoi(tmp);
			tmp = ft_tmp_to_char(tmp, ',');
			i++; // on passe aux coordonees read suivantes
			y++; // on passe aux coordonees map suivantes
		}
		ft_freetabtab(tab);
		x++;
	}
	close(fd);
}
