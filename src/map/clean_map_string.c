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

char	*clean_map_string(char *temp_map)
{
	char	**lines;
	int		start;
	int		end;
	char	*cleaned_temp;
	char	*trimmed_line;
	char	*set;
	char	*tmp;

	if (!temp_map)
		return (NULL);
	lines = ft_split(temp_map);
	if (!lines)
		return (NULL);
	int i = 0;
	while (lines[i])
	{
		printf("line[%d]: %s\n",i, lines[i]);
		i++;
	}
	start = 0;      //first line
	while (lines[start] && is_all_spaces(lines[start]))
		start++;
	end = 0;
	while (lines[end])
		end++;
	end--;
	while (lines[end] && is_all_spaces(lines[end]))
		end--;
	cleaned_temp = (char *)malloc(1);       //vor funkciayin karoghanam tal
	cleaned_temp[0] = '\0';
	set = " \t\r\v\f\n";
	while (start <= end)
	{
		trimmed_line = ft_strtrim(lines[start], set);
		printf("trimmed line: %s\n", trimmed_line);

		if (!trimmed_line)
		{
			free (cleaned_temp);
			free_split(lines);
			return (NULL);
		}
		if (cleaned_temp[0] != '\0')
			tmp = ft_strjoin_with_newline(cleaned_temp, trimmed_line);
		else
			tmp = ft_strjoin(cleaned_temp, trimmed_line);
		printf("cleaned_temp: %s\n", cleaned_temp);
		free(cleaned_temp);
		free(trimmed_line);
		if (!tmp)
		{
			free_split(lines);
			free(cleaned_temp);
			return (NULL);
		}
		cleaned_temp = tmp;
		start++;
	}
	free_split(lines);
	return (cleaned_temp);
}

// int main()
// {
// 	char str[] = "  \n	j  \n  fvybn    	\n      ";
// 	char *cleaned = clean_map_string(str);
// 	printf("%s\n", cleaned);
// 	free(cleaned);
// }