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
	int	col;
	int	line_len;
	int	line_count;
	char **map_2d;

	if(!temp_map)
		return (NULL);
	line_count = count_lines(temp_map);
	line_len = line_length(temp_map);
	map_2d = allocate_map(line_count);
	if(!map_2d)
		return (NULL);
	row = 0;
	col = 0;
	while(row < line_count)
	{
		map_2d[row] = allocate_line(line_len);
		if(!map_2d[row])
		{
			free_map(map_2d, row);
			return (NULL);
		}
		fill_line(map_2d[row], temp_map, &col);
		row++;
	}
	return (map_2d);	
}