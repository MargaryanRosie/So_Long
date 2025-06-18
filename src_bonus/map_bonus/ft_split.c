#include "../include/so_long_bonus.h"
#include "../include/ft_split.h"

int	word_count(char *str)
{
	int	i;
	int	wc;

	i = 0;
	wc = 0;
	while (str[i])
	{
		while (str[i] && str[i] == '\n')
			i++;
		if (str[i] && str[i] != '\n')
			wc++;
		while (str[i] && str[i] != '\n')
			i++;
	}
	return (wc);
}

void	skip_spaces(char *str, int *i)
{
	while (str[*i] && str[*i] == '\n')
		(*i)++;
}

void	loop_the_word(char *str, int *i)
{
	while (str[*i] && str[*i] != '\n')
		(*i)++;
}

char	**ft_split(char *str)
{
	int		i;
	char	**output;
	int		wc;
	int		j;

	if (!str)
		return (NULL);
	wc = word_count(str);
	if (wc == 0)
		return (NULL);
	output = (char **)malloc(sizeof(char *) * (wc + 1));
	if (!output)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		skip_spaces(str, &i);
		if (!process_word(output, str, &i, &j))
			return (NULL);
	}
	output[wc] = NULL;
	return (output);
}


// int main()
// {
// 	char str[] = "hello\nworld\nhh\naaa\nyes\n";
// 	char **str2 = ft_split(str);

// 	int i = 0;
// 	while(str2[i])
// 	{
// 		printf("%s\n", str2[i]);
// 		i++;
// 	}
// 	free(str2);
// 	return 0;
// }