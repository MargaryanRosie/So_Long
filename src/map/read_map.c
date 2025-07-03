#include "../include/so_long.h"
#include "../get_next_line/get_next_line.h"

static int	open_map_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error\ncannot open file\n", 24);
		return (-1);
	}
	return (fd);
}

static int	close_map_file(int fd)
{
	if (close(fd) == -1)
	{
		write(2, "Error\nFailed to close the file\n", 32);
		return (-1);
	}
	return (0);
}

static int	fill_rows(char **map_2d, int *j, char *cleaned)
{
	map_2d[*j] = cleaned;
	if (!map_2d[*j])
	{
		get_next_line(-42);
		write(2, "Error\nFailed to store trimmed line\n", 36);
		return (-1);
	}
	(*j)++;
	return (0);
}

static int	prepare_and_fill_rows(char **map_2d, int fd, int line_count)
{
	int		j;
	char	*line;
	char	*cleaned;

	j = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		cleaned = ft_strtrim(line, " \t\r\v\f\n");
		free(line);
		if (!cleaned)
			return (free_map(map_2d, j), -1);
		if (cleaned[0] == '\0')
		{
			free(cleaned);
			line = get_next_line(fd);
			continue ;
		}
		if (fill_rows(map_2d, &j, cleaned) == -1)
			return (free_map(map_2d, j), -1);
		line = get_next_line(fd);
	}
	map_2d[j] = NULL;
	return (0);
}

char	**fill_2d_array(int fd, char *filename)
{
	char	**map_2d;
	int		line_count;

	if (!filename)
		return (NULL);

	line_count = count_lines(filename);           //counts already cleaned lines
	if (line_count == 0)
	{
		write(2, "Error\nMap is empty or contains only whitespaces\n", 48);
		return (NULL);
	}

	map_2d = malloc(sizeof(char *) * (line_count + 1));
	if (!map_2d)
		return (NULL);
	if (prepare_and_fill_rows(map_2d, fd, line_count) == -1)
	{
		get_next_line(-42);
		return (NULL);                                          // already freed
	}
	get_next_line(-42);
	return (map_2d);
}


int main()
{
	int fd = open("maps/valid_map/valid.ber", O_RDONLY);
	if (fd < 0)
		return (1);
	char **arr_2d;

	arr_2d = fill_2d_array(fd, "maps/valid_map/valid.ber");
	if (!arr_2d)
	{
		close(fd);
		get_next_line(-42);
		return (1); 
	}
	int i = 0;
	while (arr_2d[i])
	{
		printf("%s\n", arr_2d[i]);
		i++;
	}
	free_map(arr_2d, i);
	close(fd);
}
