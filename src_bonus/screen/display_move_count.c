#include "so_long_bonus.h"


static char	*join_strings(char *s1, char *s2)
{
	char	*ptr;
	char	*start;

	if (!s1 || !s2)
		return (NULL);
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ptr)
		return (NULL);
	start = ptr;
	while (*s1)
	{
		*ptr = *s1;
		ptr++;
		s1++;
	}
	while (*s2)
	{
		*ptr = *s2;
		ptr++;
		s2++;
	}
	*ptr = '\0';
	return (start);
}

void	display_move_count(t_game *game)
{
	char	*move_str;
	char	*str;
	char	*num;

	num = ft_itoa(game->moves);
	str = "Moves: ";
	move_str = join_strings(str, num);
	mlx_string_put(game->mlx, game->window, 10, 10, 0xFFFFFF, move_str);
	free(num);
	free(move_str);
}