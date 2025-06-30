#include "get_next_line.h"
#include "../include/so_long.h"
#include "../include/ft_split.h"

char	*extract_line(char *str)
{
	int		index;
	char	*extracted_line;

	if (!str || !str[0])
		return (NULL);
	index = find_newline(str);
	if (index == -1)
		index = ft_strlen(str);
	extracted_line = (char *)malloc(sizeof(char) * (index + (str[index] == '\n')
				+ 1));
	if (!extracted_line)
		return (NULL);
	ft_strncpy(extracted_line, str, index + (str[index] == '\n'));
	extracted_line[index + (str[index] == '\n')] = '\0';
	return (extracted_line);
}

char	*get_remaining(char *str)
{
	int		index;
	char	*remaining_part;
	int		remaining_length;

	if (!str)
		return (NULL);
	index = find_newline(str);
	if (index == -1)
	{
		free(str);
		return (NULL);
	}
	index++;
	remaining_length = ft_strlen(str) - index;
	remaining_part = (char *)malloc(sizeof(char) * (remaining_length + 1));
	if (!remaining_part)
		return (free(str), NULL);
	ft_strncpy(remaining_part, str + index, remaining_length);
	remaining_part[remaining_length] = '\0';
	free(str);
	return (remaining_part);
}

int	read_file(int fd, char **remaining_part)
{
	char	*file_content;
	int		bytes_read;

	file_content = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!file_content)
		return (-1);
	while (1)
	{
		bytes_read = read(fd, file_content, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(file_content);
			return (-1);
		}
		if (bytes_read == 0)
			return (free(file_content), 0);
		file_content[bytes_read] = '\0';
		*remaining_part = ft_strjoin(*remaining_part, file_content);
		if (!(*remaining_part))
			return (free(file_content), -1);
		if (find_newline(file_content) != -1)
			break ;
	}
	return (free(file_content), 1);
}

void	clean_remaining_part(char **remaining_part)
{
	free(*remaining_part);
	*remaining_part = NULL;
}

char	*get_next_line(int fd)
{
	static char	*remaining_part = NULL;
	char		*extracted_line;
	int			res;

	if (fd < 0 || BUFFER_SIZE < 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	if (fd == -42)
		return(clean_remaining_part(&remaining_part), NULL);
	if (!remaining_part)
		remaining_part = ft_strdup("");
	if (!remaining_part)
		return (NULL);
	if (find_newline(remaining_part) == -1)
	{
		res = read_file(fd, &remaining_part);
		if (res == -1 || (res == 0
				&& (!remaining_part || remaining_part[0] == '\0')))
			return (clean_remaining_part(&remaining_part), NULL);
	}
	extracted_line = extract_line(remaining_part);
	if (!extracted_line)
		return (clean_remaining_part(&remaining_part), NULL);
	remaining_part = get_remaining(remaining_part);
	return (extracted_line);
}