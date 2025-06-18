#include "../include/so_long_bonus.h"

static char	**alloc_map(int line_count)
{
	char	**map_2d;

	map_2d = allocate_map(line_count);
	if (!map_2d)
		write(2, "Error: map alloc failed\n", 24);
	return (map_2d);
}

static int	line_length(char *temp_map, int pos)
{
	int	this_line_len;

	this_line_len = 0;
	while (temp_map[this_line_len + pos]
		&& temp_map[this_line_len + pos] != '\n')
		this_line_len++;
	return (this_line_len);
}

static int	fill_row(char **map_2d, char *temp_map, int row, int *pos)
{
	int	len;

	len = line_length(temp_map, *pos);
	map_2d[row] = allocate_line(len);
	if (!map_2d[row])
		return (0);
	fill_line(map_2d[row], temp_map, pos);
	return (1);
}

char	**fill_2d_array(char *temp_map)
{
	char	**map_2d;
	int		row;
	int		pos;
	int		line_count;

	if (!temp_map)
		return (NULL);
	line_count = count_lines(temp_map);
	map_2d = alloc_map(line_count);
	if (!map_2d)
		return (NULL);
	row = 0;
	pos = 0;
	while (row < line_count)
	{
		if (!fill_row(map_2d, temp_map, row, &pos))
		{
			free_map(map_2d, row);
			return (NULL);
		}
		row++;
	}
	return (map_2d);
}