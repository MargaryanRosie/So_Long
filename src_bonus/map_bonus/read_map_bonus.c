#include "../include/so_long_bonus.h"
#include "../get_next_line/get_next_line.h"
#include "../include/ft_split.h"

static int	is_only_whitespace(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'
			&& str[i] != '\v' && str[i] != '\f' && str[i] != '\r')
			return (0);
		i++;
	}
	return (1);
}

static	int	check_map_blank_lines(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == '\n' && str[i + 1] == '\n')
			|| (str[i] == '\r' && str[i + 1] == '\r'))
		{
			write(2, "Error\nMap contains blank lines\n", 31);
			free(str);
			close(fd);
			exit(1);
		}
		i++;
	}
	return (1);
}

static void	check_blank_inside(char **str)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[i])
	{
		tmp = str[i];
		str[i] = ft_strtrim_for_end(str[i], " \t\v\f\r");
		free(tmp);
		i++;
	}
}

static char	*read_and_join_lines(int fd)
{
	char	*line;
	char	*joined;
	char	*tmp;

	joined = ft_strdup("");
	line = get_next_line(fd);
	while (line)
	{
		tmp = joined;
		joined = join_strings(joined, line);
		free(tmp);
		free(line);
		line = get_next_line(fd);
	}
	return (joined);
}

char	**get_2d_array(int fd)
{
	char	*joined;
	char	*tmp;
	char	**map_2d;

	joined = read_and_join_lines(fd);
	if (is_only_whitespace(joined))
	{
		write(2, "Error\nMap is empty or contains only whitespaces\n", 48);
		free(joined);
		close(fd);
		exit(1);
	}
	tmp = joined;
	joined = ft_strtrim(joined, " \t\n\v\f\r");
	free(tmp);
	check_map_blank_lines(joined, fd);
	map_2d = ft_split(joined);
	if (!map_2d)
		return (free(joined), NULL);
	check_blank_inside(map_2d);
	free(joined);
	get_next_line(-42);
	return (map_2d);
}
