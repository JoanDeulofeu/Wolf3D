#include "wolf3d.h"

void	ft_usage(int usage)
{
	if (usage == -1)
		ft_putstr("Error : Malloc failed\n");
	if (usage == 1)
		ft_putstr("Usage : ./Wolf3d map_file.txt\n");
	if (usage == 2)
		ft_putstr("Warning : Invalid file\n");
	if (usage == 4)
		ft_putstr("---Warning : Invalid file\n");
	exit(0);
}

int main(int ac, char **av)
{
	t_s *s;
	// (void)av;
	// (void)ac;
	if (ac != 2)
		ft_usage(1);
	if (!(s = (t_s *)malloc(sizeof(t_s))))
		return (0);
	s->high = 0;
	s->width = 0;
	ft_check(s, av[1]);
	ft_init_struct(s);
	ft_parsing(s, av[1]);
	// ft_display(s);
	return (0);
}
