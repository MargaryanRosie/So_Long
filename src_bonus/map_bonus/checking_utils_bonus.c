static int	finalize_min_count(int min_count)
{
	if (min_count == -1)
		return (0);
	return (min_count);
}

int	get_min_whitespaces(char **map)
{
	int	i;
	int	min_count;
	int	count;
	int	j;

	i = 0;
	min_count = -1;
	while (map[i])
	{
		j = 0;
		count = 0;
		while (map[i][j] == ' ' || map[i][j] == '\t')
		{
			count++;
			j++;
		}
		if (map[i][j] != '\0' && (min_count == -1 || count < min_count))
			min_count = count;
		i++;
	}
	return (finalize_min_count(min_count));
}
