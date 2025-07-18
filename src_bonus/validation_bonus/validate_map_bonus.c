#include "../include/so_long_bonus.h"
#include "../get_next_line/get_next_line.h"

int	is_surrounded_by_walls(char **map)
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

int	validate_file_name(char *filename)
{
	int	len;

	if (!filename)
		return (0);
	len = ft_strlen(filename);
	if (len < 4)
		return (0);
	if (filename[len - 4] != '.'
		|| filename[len - 3] != 'b'
		|| filename[len - 2] != 'e'
		|| filename[len - 1] != 'r')
		return (0);
	return (1);
}

int	validate_structure(char **map)
{
	if (is_rectangular(map) == 0)
	{
		write(2, "Error\nInvalid Map: The map is not rectangular\n", 47);
		return (0);
	}
	if (is_surrounded_by_walls(map) == 0)
	{
		write(2, "Error\nInvalid Map: ", 20);
		write(2, "The map is not fully surrounded by walls\n", 42);
		return (0);
	}
	if (is_valid_path(map) == 0)
	{
		write(2, "Error\nInvalid Map: The game is not playable\n", 45);
		return (0);
	}
	return (1);
}

int	validate_content(char **map)
{
	if (has_valid_components(map) == 0)
	{
		write(2, "Error\nInvalid Map:", 19);
		write(2, " The map contains not valid components\n", 40);
		return (0);
	}
	if (has_basic_components(map) == 0)
	{
		write(2, "Error\nInvalid Map:", 19);
		write(2, " The map doesnt have the basic components\n", 43);
		return (0);
	}
	if (has_valid_num_of_elements(map) == 0)
	{
		write(2, "Error\nInvalid Map:", 19);
		write(2, " The map doesnt have valid number of elements\n", 47);
		return (0);
	}
	return (1);
}

int	validate_map(char **map)
{
	if (validate_structure(map) && validate_content(map))
		return (1);
	return (0);
}