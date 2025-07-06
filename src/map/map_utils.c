#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/so_long.h"
#include "../get_next_line/get_next_line.h"

int	count_lines(char *filename)
{
	int		fd;
	char	*cleaned;
	int		count;
	char	*line;

	count = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		cleaned = ft_strtrim(line, " \t\r\v\f\n");
		free(line);
		if (!cleaned)
			return (get_next_line(-42), close(fd), -1);
		if (cleaned[0] != '\0')
			count++;
		line = get_next_line(fd);
		free(cleaned);
	}
	get_next_line(-42);
	if (close(fd) == -1)
		return (-1);
	return (count);
}

int	line_length(int fd)
{
	char	buffer[1];
	int		line_length;
	int		bytes_read;

	line_length = 0;
	bytes_read = read(fd, buffer, 1);
	while (bytes_read == 1)
	{
		if (buffer[0] == '\n')
			break ;
		line_length++;
		bytes_read = read(fd, buffer, 1);
	}
	if (bytes_read == -1)
	{
		write(2, "Error\nFailed to read the file\n", 30);
		return (-1);
	}
	return (line_length);
}