#include "../include/so_long.h"
//• The map can be composed of only these 5 characters

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

//this is for the design part, if the game is playable or not we will check in another function
int	has_basic_components(char **map)
{
	int collectibles;
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

int has_valid_num_of_elements(char **map)
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

int	is_rectangular(char **map)
{
	int	i;
	int	first_len;

	if (!map || !map[0])
		return (0);
	first_len = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (first_len != ft_strlen(map[i]))
			return (0);
		i++;
	}
	return (1);
}


int is_surrounded_by_walls(char **map)
{
	int	i;
	int	height;
	int	width;

	height = 0;
	while (map[height])
		height++;
	width = ft_strlen(map[0]);
	i = 0;
	while (map[0][i] && map[height - 1][i])
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

