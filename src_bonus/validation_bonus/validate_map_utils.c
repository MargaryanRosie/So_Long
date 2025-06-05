#include "../include/so_long_bonus.h"
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
				&& map[i][j] != 'P' && map[i][j] != '0' && map[i][j] != 'M')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static void	set_flags(char c, t_components *components)
{
	if (c == '1')
		components->walls = 1;
	else if (c == 'C')
		components->collectibles = 1;
	else if (c == '0')
		components->space = 1;
	else if (c == 'M')
		components->enemy = 1;
}

//this is for the design part, if the game is playable or not we will check in another function
int	has_basic_components(char **map)
{
	t_components	components;
	int				i;
	int				j;

	components.collectibles = 0;
	components.walls = 0;
	components.space = 0;
	components.enemy = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			set_flags(map[i][j], &components);
			if (components.walls && components.space
				&& components.collectibles && components.enemy)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static void	count_elements(char ch, t_counter *count)
{
	if (ch == 'C')
		(count->c)++;
	else if (ch == 'P')
		(count->p)++;
	else if (ch == 'E')
		(count->e)++;
	else if (ch == 'M')
		(count->enm)++;
}


int	has_valid_num_of_elements(char **map)
{
	int			i;
	int			j;
	t_counter	counter;

	counter.c = 0;
	counter.p = 0;
	counter.e = 0;
	counter.enm = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			count_elements(map[i][j], &counter);
			j++;
		}
		i++;

	}
	return (counter.c >= 1 && counter.enm >= 1 
		&& counter.p == 1 && counter.e == 1);
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

