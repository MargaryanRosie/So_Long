#include "../include/so_long_bonus.h"
#include "../include/ft_split.h"

void	free_remaining(char **output, int j)
{
	while (j >= 0)
	{
		free(output[j]);
		output[j] = NULL;
		j--;
	}
	free(output);
	output = NULL;
}

char	*ft_strncpy(char *dest, char *src, int n)
{
	int	i;

	if (!dest || !src)
		return (NULL);
	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	allocate_word(char **output, char *str, int start, int i, int j)
{
	int	word_len;

	word_len = i - start;
	output[j] = (char *)malloc(sizeof(char) * (word_len + 1));
	if (!output[j])
	{
		free_remaining(output, j);
		return (0);
	}
	ft_strncpy(output[j], &str[start], word_len);
	return (1);
}

int	process_word(char **output, char *str, int *i, int *j)
{
	int start;

	start = *i;
	loop_the_word(str, i);
	if (*i > start)
	{
		if (!allocate_word(output, str, start, *i, *j))
			return (0);
		(*j)++;
	}
	return (1);
}