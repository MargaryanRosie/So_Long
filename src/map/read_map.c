#include "../include/so_long.h"
#include "../get_next_line/get_next_line.h"

static int	open_map_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error\ncannot open file\n", 23);
		return (-1);
	}
	return (fd);
}

static int	close_map_file(int fd)
{
	if (close(fd) == -1)
	{
		write(2, "Error\nFailed to close the file\n", 31);
		return (-1);
	}
	return (0);
}

static int	fill_rows(char **map_2d, int fd, char *filename, int line_count)
{
	int	i;

	i = 0;
	while (i < line_count)
	{
		map_2d[i] = get_next_line(fd);
		if (!map_2d[i])
		{
			get_next_line(-42);
			write(2, "Error\nFailed to read the map file\n", 34);
			free_map(map_2d, i);
			return (-1);
		}
		i++;
	}
	map_2d[i] = NULL;
	return (0);
}

char	**fill_2d_array(int fd, char *filename)
{
	int		i;
	char	**map_2d;
	int		line_count;

	if (!filename)
		return (NULL);
	line_count = count_lines(fd, filename);
	map_2d = (char **)malloc(sizeof(char *) * (line_count + 1));
	if (!map_2d)
		return (NULL);
	if (close_map_file(fd) == -1)
		return (free(map_2d), NULL);
	fd = open_map_file(filename);
	if (fd == -1)
		return (free(map_2d), NULL);
	if (fill_rows(map_2d, fd, filename, line_count) == -1)
	{
		get_next_line(-42);
		return (free(map_2d), NULL);
	}
	get_next_line(-42);
	close_map_file(fd);
	return (map_2d);
}

int main()
{
	int fd = open("maps/valid_map/valid.ber", O_RDONLY);
	printf("fd: %d\n", fd);
	if (fd < 0)
		return (1);
	char **arr_2d;

	arr_2d = fill_2d_array(fd, "maps/valid_map/valid.ber");
	if (!arr_2d)
	{
		get_next_line(-42);
		return (1); 
	}
	int i = 0;
	while (arr_2d[i])
	{
		printf("%s", arr_2d[i]);
		i++;
	}
	get_next_line(-42);
	free_map(arr_2d, i);
}