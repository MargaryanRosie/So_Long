#include "get_next_line.h"
#include "../include/so_long.h"
#include "../include/ft_split.h"

int	find_newline(char *str)
{
	int	i;

	if (!str)
	{
		return (-1);
	}
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*new_string;
	int		i;
	int		j;

	if (!str1 || !str2)
		return (free(str1), NULL);
	new_string = (char *)malloc(sizeof(char) * (ft_strlen(str1)
				+ ft_strlen(str2) + 1));
	if (!new_string)
		return (free(str1), NULL);
	i = 0;
	while (str1[i])
	{
		new_string[i] = str1[i];
		i++;
	}
	j = 0;
	while (str2[j])
		new_string[i++] = str2[j++];
	new_string[i] = '\0';
	free(str1);
	return (new_string);
}

char	*ft_strdup(char *s)
{
	int		i;
	char	*new_str;
	int		len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	new_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new_str[i] = s[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}