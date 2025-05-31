#include "so_long.h"

int read_map(char *filename, char *temp_map)
{
	char	ch;
	int		fd;
	int		bytes_read;
	int		i;

	fd = open(filename, O_RDONLY);
	if(fd < 0)
		return 1;
	i = 0;
	while((bytes_read = read(fd, &ch, 1)) > 0)
	{
		temp_map[i] = ch;
		i++;
	}
	if(bytes_read < 0)
		return 2;
	temp_map[i] = '\0';
	close(fd);
	return (bytes_read);	
}

char **fill_2d_array(char *temp_map)
{
	int	row;
	int	pos;
	int	line_len;
	int	line_count;
	char **map_2d;

	if(!temp_map)
		return (NULL);
	line_count = count_lines(temp_map);
	printf("line_count: %d\n", line_count);
	line_len = line_length(temp_map);
	printf("line_len: %d\n", line_len);
	map_2d = allocate_map(line_count);
	if(!map_2d)
		return (NULL);
	row = 0;
	pos = 0;
	while (row < line_count)
	{
		//printf("row: %d\n", row);
		map_2d[row] = allocate_line(line_len);
		//printf("map_2d[%d]: %s\n", row, map_2d[row]);
		if (!map_2d[row])
		{
			write(2, "Allocation for line failed", 27);
			free_map(map_2d, row);
			return (NULL);
		}
		//printf("pos: %d\n", pos);
		fill_line(map_2d[row], temp_map, &pos);
		//printf("filled line: %s\n", map_2d[row]);
		row++;
	}
	return (map_2d);	
}