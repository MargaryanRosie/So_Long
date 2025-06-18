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
	while (s[i] && is_in_set(s[i], set))
		i++;
	*start = i;
	if (s[i] == '\0')  // All characters are c
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

	if (!s)
		return (NULL);
	len = find_len(s, set, &start);
	printf("len: %d\n", len);
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