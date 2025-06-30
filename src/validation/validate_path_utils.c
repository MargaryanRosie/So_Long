#include "../include/so_long.h"
#include "../get_next_line/get_next_line.h"

// char	*ft_strdup(char *str)
// {
// 	int	i;
// 	char *copy;

// 	if (!str)
// 		return (NULL);
// 	i = 0;
// 	while (str[i])
// 		i++;
// 	copy = (char *)malloc(sizeof(char) * (i + 1));
// 	if (!copy)
// 		return (NULL);
// 	i = 0;
// 	while (str[i])
// 	{
// 		copy[i] = str[i];
// 		i++;
// 	}
// 	copy[i] = '\0';
// 	return (copy);
// }

void	find_player(char **map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				*x = j;
				*y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

char	**copy_map(char **map)
{
	char	**copy;
	int		i;

	i = 0;
	while (map[i])
		i++;
	copy = (char **)malloc(sizeof(char *) * (i + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (map[i])
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			free_map(copy, i);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	flood_fill(char **map, int x, int y)     //start from (x,y) position
{
	if (map[y][x] == 'V' || map[y][x] == '1')
		return ;
	map[y][x] = 'V';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

int	check_if_unreachable(char **copy)
{
	int	i;
	int	j;

	i = 0;
	while (copy[i])
	{
		j = 0;
		while (copy[i][j])
		{
			if (copy[i][j] == 'C' || copy[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}