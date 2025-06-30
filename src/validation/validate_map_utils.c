#include "../include/so_long.h"

//check if there are no other invalid components
int	has_valid_components(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != 'C' && map[i][j] != 'E'
				&& map[i][j] != 'P' && map[i][j] != '0')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static void	set_flags(char c, int *col, int *wall, int *space)
{
	if (c == '1')
		*wall = 1;
	else if (c == 'C')
		*col = 1;
	else if (c == '0')
		*space = 1;
}


//check if the map has the 3 basic components(col, wall, space)
int	has_basic_components(char **map)
{
	int	collectibles;
	int	walls;
	int	space;
	int	i;
	int	j;

	collectibles = 0;
	walls = 0;
	space = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			set_flags(map[i][j], &collectibles, &walls, &space);
			if (walls && space && collectibles)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static void	count_elements(char ch, int *c, int *p, int *e)
{
	if (ch == 'C')
		(*c)++;
	else if (ch == 'P')
		(*p)++;
	else if (ch == 'E')
		(*e)++;
}

//check if the number of components is valid
int	has_valid_num_of_elements(char **map)
{
	int	i;
	int	j;
	int	c;
	int	p;
	int	e;

	c = 0;
	p = 0;
	e = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			count_elements(map[i][j], &c, &p, &e);
			j++;
		}
		i++;
	}
	return (c >= 1 && p == 1 && e == 1);
}