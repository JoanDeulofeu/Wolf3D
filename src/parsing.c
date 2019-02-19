#include "wolf3d.h"

char	*ft_tmp_to_char(char *tmp, char c)
{
	while (tmp[0] != c) //avance jusqu'a la virgule
		tmp++;
	tmp++; //puis juste apres la virgule
	return (tmp);
}

void	ft_check_comma(char *block) // comma = virgule en Anglais
{
	int i;
	int comma;

	i = 0;
	comma = 0;
	if (block[i] < 48 || block[i] > 57)
		ft_usage(2);
	while (block[i] != '\0')
	{
		if (block[i] == ',' && block[i+1] == ',')
			ft_usage(2);
		if (block[i] == ',')
			comma += 1;
		i++;
	}
	if (block[i] == ',' || comma != 4)
		ft_usage(2);
}

void	ft_parsing(t_s *s, char *av)
{
	int		fd;
	int		i;
	int		x;
	int		y;
	char	*line;
	char	**tab;
	char	*tmp;

	fd = open(av, O_RDONLY);
	i = 0;
	x = 0;
	while (get_next_line(fd, &line)) //tant que le fichier est pas fini
	{
		y = 0;
		i = 0;
		tab = ft_strsplit(line, ' ');
		while (i < s->width) //tant que la ligne est pas fini
		{
			// ft_putstr("test0\n");
			tmp = tab[i];
			// ft_putstr("test1\n");
			ft_check_comma(tmp);
			// ft_putstr("test2\n");
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
			ft_putstr("test\n");
		}
		ft_putstr("\n");
		ft_freetabtab(tab);
		x++;
		ft_memdel((void **)&line);
	}
	close(fd);
	// ft_check_post_pars(s);
}
