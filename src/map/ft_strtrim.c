#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/so_long.h"

static int	is_in_set(char c, char *set)
{
	int	i;

	if (!set)
		return (0);
	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	find_len(char *s, char *set, int *start)
{
	int	i;
	int	end;
	int	len;

	i = 0;
	len = 0;
	while (s[i] && is_in_set(s[i], set))
		i++;
	while (s[i] != '\n' && i != 0)
		i--;
	*start = i;
	if (s[i] == '\0')
		return (0);
	end = i;
	while (s[end])
		end++;
	end--;
	while (end >= *start && is_in_set(s[end], set))
		end--;
	len = end - *start + 1;
	return (len);
}

char	*ft_strtrim(char *s, char *set)
{
	int		start;
	char	*new;
	int		len;
	int		i;

	if (!s || !set)
		return (NULL);
	len = find_len(s, set, &start);
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	new[len] = '\0';
	i = 0;
	if (len != 0)
	{
		while (s[start] && i < len)
		{
			new[i] = s[start];
			start++;
			i++;
		}
	}
	return (new);
}

static char	*return_empty_string(void)
{
	char	*trimmed;

	trimmed = malloc(1);
	if (!trimmed)
		return (NULL);
	trimmed[0] = '\0';
	return (trimmed);
}

char	*ft_strtrim_for_end(char *s, char *set)
{
	int		start;
	int		i;
	char	*trimmed;

	if (!s || !set)
		return (NULL);
	trimmed = NULL;
	start = ft_strlen(s) - 1;
	while (start >= 0 && is_in_set(s[start], set))
		start--;
	if (start < 0)
		return (return_empty_string());
	trimmed = malloc(sizeof(char) * (start + 2));
	if (!trimmed)
		return (NULL);
	i = 0;
	while (i <= start)
	{
		trimmed[i] = s[i];
		i++;
	}
	trimmed[i] = '\0';
	return (trimmed);
}
