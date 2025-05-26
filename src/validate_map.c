#include "so_long.h"

int	validate_structure(char **map)
{
	if (is_rectangular(map) == 0)
	{
		write(2, "Error: The map is not rectangular\n", 35);
		return (0);
	}
	if (is_surrounded_by_walls(map) == 0)
	{
		write(2, "The map is not fully surrounded by walls\n", 42);
		return (0);
	}
	if (is_valid_path(map) == 0)
	{
		write(2, "The game is not playable\n", 26);
		return (0);
	}
	return (1);
}

int	validate_content(char **map)
{
	if (has_valid_components(map) == 0)
	{
		write(2, "Error: The map contains not valid components\n", 46);
		return (0);
	}
	if (has_basic_components(map) == 0)
	{
		write(2, "Error: The map doesnt have the basic components\n", 49);
		return (0);
	}
	if (has_valid_num_of_elements(map) == 0)
	{
		write(2, "The map doesnt have valid number of elements\n", 46);
		return (0);
	}
	return (1);
}

int	validate_map(char **map)
{
	if(validate_structure(map) && validate_content(map))
		return (1);
	return (0);
}