#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/so_long.h"

int	count_lines(char *temp_map)
{
	int	line_count;
	int	i;

	if (temp_map == NULL)
		return (0);
	line_count = 0;
	i = 0;
	while (temp_map[i])
	{
		if (temp_map[i] == '\n')
			line_count++;
		i++;
	}
	return (line_count + 1);     //cause in the last line there is no newline
}

int	line_length(char *temp_map)
{
	int	line_len;

	if (temp_map == NULL)
		return (0);
	line_len = 0;
	while (temp_map[line_len] != '\n' && temp_map[line_len])
	{
		line_len++;
	}
	return (line_len);
}

char	**allocate_map(int line_count)
{
	char	**map_2d;

	map_2d = (char **)malloc((line_count + 1) * sizeof(char *));
	if (!map_2d)
		return (NULL);
	map_2d[line_count] = NULL;
	return (map_2d);
}

char	*allocate_line(int line_length)
{
	char	*line;

	line = (char *)malloc((line_length + 1) * sizeof(char));
	if (!line)
		return (NULL);
	line[line_length] = '\0';
	return (line);
}

void	fill_line(char *line, char *temp_map, int *index)
{
	int	i;

	i = 0;
	while (temp_map[*index] && temp_map[*index] != '\n')
	{
		line[i] = temp_map[*index];
		(*index)++;
		i++;
	}
	if (temp_map[*index] == '\n')
		(*index)++;
}
// int main()
// {
// 	char str[] = "	hello  	    ";
// 	char set[] = " 	";
// 	char *new_str = ft_strtrim(str, set);

// 	printf("%s\n", new_str);         // 'hello'
// 	// printf("'%s'\n", ft_strtrim("   hello", ' '));      // 'hello'
// 	// printf("'%s'\n", ft_strtrim("hello   ", ' '));      // 'hello'
// 	// printf("'%s'\n", ft_strtrim("      ", ' '));        // ''
// 	// printf("'%s'\n", ft_strtrim("", ' '));              // ''

// 	free (new_str);
// 	return 0;
// }