#include "../include/so_long_bonus.h"

int read_map(char *filename, char *temp_map)
{
	char	ch;
	int		fd;
	int		bytes_read;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (1);
	i = 0;
	bytes_read = read(fd, &ch, 1);
	//printf("first element: %c\n", temp_map[i]);
	while (bytes_read > 0)
	{
		temp_map[i] = ch;
		i++;
		bytes_read = read(fd, &ch, 1);
	}
	if (i == 0)
	{
		write(2, "The file is empty\n", 18);
		exit(2);
	}
	if (bytes_read < 0)
		return (1);
	temp_map[i] = '\0';
	close(fd);
	return (bytes_read);
}

char	**fill_2d_array(char *temp_map)
{
	int		row;
	int		pos;
	//int		line_len;
	int		this_line_len;
	int		line_count;

	char	**map_2d;

	if (!temp_map)
		return (NULL);
	line_count = count_lines(temp_map);
	//line_len = line_length(temp_map);
	map_2d = allocate_map(line_count);
	if (!map_2d)
		return (NULL);
	row = 0;
	pos = 0;
	while (row < line_count)
	{
		this_line_len = 0;
		while (temp_map[this_line_len + pos] && temp_map[this_line_len + pos] != '\n')
			this_line_len++;
		map_2d[row] = allocate_line(this_line_len);
		if (!map_2d[row])
		{
			write(2, "Allocation for line failed", 27);
			free_map(map_2d, row);
			return (NULL);
		}
		fill_line(map_2d[row], temp_map, &pos);
		row++;
	}
	return (map_2d);
}