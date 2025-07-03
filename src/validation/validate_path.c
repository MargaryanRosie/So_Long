#include "../include/so_long.h"
#include "../get_next_line/get_next_line.h"

int	is_valid_path(char **map)
{
	char	**copy;
	int		x;
	int		y;
	int		is_unreachable;
	int		i;

	i = 0;
	while (map[i])
		i++;
	copy = copy_map(map);
	if (!copy)
		return (0);
	if (!find_player(copy, &x, &y))
	{
		free_map(copy, i);
		return (0);
	}
	flood_fill(copy, x, y);
	is_unreachable = check_if_unreachable(copy);
	free_map(copy, i);
	if (is_unreachable == 0)     //unreachable found
		return (0);
	else
		return (1);
}