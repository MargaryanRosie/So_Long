#include "../include/so_long_bonus.h"

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
				&& map[i][j] != 'P' && map[i][j] != '0' && map[i][j] != 'M')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	has_basic_components(char **map)
{
	int	collectibles;
	int	walls;
	int	i;
	int	j;

	collectibles = 0;
	walls = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				walls = 1;
			else if (map[i][j] == 'C')
				collectibles = 1;
			if (walls && collectibles)
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
