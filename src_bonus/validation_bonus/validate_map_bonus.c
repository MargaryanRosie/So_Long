#include "../include/so_long_bonus.h"

int	validate_structure(char **map)
{
	if (is_rectangular(map) == 0)
	{
		write(2, "Error\nInvalid Map: The map is not rectangular\n", 47);
		return (0);
	}
	if (is_surrounded_by_walls(map) == 0)
	{
		write(2, "Error\n", 7);
		write(2, "Invalid Map: The map is not fully surrounded by walls\n", 55);
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
		write(2, "Error\nInvalid Map: The map contains not valid components\n", 58);
		return (0);
	}
	if (has_basic_components(map) == 0)
	{
		write(2, "Error\nInvalid Map: The map doesnt have the basic components\n", 61);
		return (0);
	}
	if (has_valid_num_of_elements(map) == 0)
	{
		write(2, "Error\nInvalid Map: The map doesnt have valid number of elements\n", 65);
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