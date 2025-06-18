#include "../include/so_long_bonus.h"
#include "../include/ft_split.h"

char	*clean_map_string(char *temp_map)
{
	char	**lines;
	int		start;
	int		end;
	char	*cleaned_temp;

	if (!temp_map)
		return (NULL);
	lines = ft_split(temp_map);
	if (!lines)
		return (NULL);
	get_line_bounds(lines, &start, &end);
	printf("start: %d\nend: %d\n", start, end);
	cleaned_temp = join_cleaned_lines(lines, start, end);
	if (!cleaned_temp)
	{
		free_split(lines);
		return (NULL);
	}
	free_split(lines);
	return (cleaned_temp);
}