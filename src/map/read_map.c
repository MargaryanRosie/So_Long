#include "../include/so_long.h"

static int	open_map_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		write(2, "Error\ncannot open file\n", 24);
	return (fd);
}

static int	read_into_buffer(int fd, char *temp_map)
{
	int	bytes_read;
	int	i;
	char	ch;

	i = 0;
	bytes_read = read(fd, &ch, 1);
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
	temp_map[i] = '\0';
	return (bytes_read);
}

int	read_map(char *filename, char *temp_map)
{
	int		fd;
	int		bytes_read;

	fd = open_map_file(filename);
	if (fd < 0)
		return (1);
	bytes_read = read_into_buffer(fd, temp_map);
	if (bytes_read < 0)
		return (1);
	close(fd);
	return (bytes_read);
}
