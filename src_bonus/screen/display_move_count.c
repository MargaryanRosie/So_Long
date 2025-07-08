#include "so_long_bonus.h"

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