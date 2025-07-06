#include "../include/so_long.h"
#include "../get_next_line/get_next_line.h"
#include "../include/ft_split.h"

static	int	check_map_blank_lines(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
		{
			write(2, "Error\nMap contains blank lines\n", 31);
			free(str);
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

char	**get_2d_array(int fd)
{
	char	*current_line;
	char	*joined;
	char	*tmp;
	char	**map_2d;

	joined = ft_strdup("");
	current_line = get_next_line(fd);
	while (current_line)
	{
		tmp = joined;
		joined = join_strings(joined, current_line);
		free(tmp);
		free(current_line);
		current_line = get_next_line(fd);
	}
	tmp = joined;
	joined = ft_strtrim(joined, " \t\n\v\f\r");
	free(tmp);
	check_map_blank_lines(joined);
	map_2d = ft_split(joined);
	check_blank_inside(map_2d);
	free(joined);
	get_next_line(-42);
	return (map_2d);
}
