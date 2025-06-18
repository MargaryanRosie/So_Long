#include "../include/so_long.h"
#include "../include/ft_split.h"

int	is_all_spaces(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != ' ' && !(s[i] >= 9 && s[i] <= 13))
			return (0);
		i++;
	}
	return (1);
}

void	free_split(char **split)
{
	int	i = 0;

	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
}

void	get_line_bounds(char **lines, int *start, int *end)
{
	*start = 0;
	while (lines[*start] && is_all_spaces(lines[*start]))
		(*start)++;
	*end = 0;
	while (lines[*end])
		(*end)++;
	(*end)--;
	while (lines[*end] && is_all_spaces(lines[*end]))
		(*end)--;
}

char	*append_trimmed_line(char *cleaned_temp, char *line, char *set)
{
	char	*trimmed_line;
	char	*tmp;

	if (!cleaned_temp || !line || !set)
		return (NULL);
	trimmed_line = ft_strtrim(line, set);
	if (!trimmed_line)
		return (NULL);
	if (cleaned_temp[0] != '\0')
		tmp = ft_strjoin_with_newline(cleaned_temp, trimmed_line);
	else
		tmp = ft_strjoin(cleaned_temp, trimmed_line);
	free(cleaned_temp);
	free(trimmed_line);
	return (tmp);
}

char	*join_cleaned_lines(char **lines, int start, int end)
{
	char	*cleaned_temp;
	char	*tmp;

	cleaned_temp = (char *)malloc(1);
	if (!cleaned_temp)
		return (NULL);
	cleaned_temp[0] = '\0';
	while (start <= end)
	{
		tmp = append_trimmed_line(cleaned_temp, lines[start], " \t\r\v\f\n");
		if (!tmp)
		{
			free(cleaned_temp);
			return (NULL);
		}
		cleaned_temp = tmp;
		start++;
	}
	return (cleaned_temp);
}

// int main()
// {
// 	char str[] = "  \n	j  \n  fvybn    	\n   hga  ua \n   ";
// 	char *cleaned = clean_map_string(str);
// 	printf("%s\n", cleaned);
// 	free(cleaned);
// }