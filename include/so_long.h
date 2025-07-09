#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>
# include <stdlib.h>
# include <../mlx/mlx.h>

# define TILE_SIZE 96

typedef struct s_game
{
	void	*mlx;
	void	*window;
	char	**map;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		moves;
	int		collectibles;
	void	*img_wall_ml;
	void	*img_wall_rd;
	void	*img_wall_dl;
	void	*img_wall_dm;
	void	*img_wall_rm;
	void	*img_wall_tl;
	void	*img_wall_tm;
	void	*img_wall_tr;
	void	*img_wall_stone;
	void	*img_floor;
	void	*img_player;
	void	*img_player_r;
	void	*img_player_b;
	void	*img_player_f;
	void	*img_player_l;
	void	*img_exit;
	void	*img_collectible;
}	t_game;

int		count_lines(char *temp_map);
char	**allocate_map(int line_count);
char	*allocate_line(int line_length);
void	free_map(char **map_2d, int rows_allocated);
int		read_map(char *filename, char *temp_map);
char	**fill_2d_array(int fd, char *filename);
void	fill_line(char *line, char *temp_map, int *index);
int		is_valid_path(char **map);
int		check_if_unreachable(char **copy);
void	flood_fill(char **map, int x, int y);
char	**copy_map(char **map);
int		find_player(char **map, int *x, int *y);
int		validate_file_name(char *filename);
char	*ft_strdup(char *str);
int		has_valid_components(char **map);
int		has_basic_components(char **map);
int		has_valid_num_of_elements(char **map);
int		validate_structure(char **map);
int		validate_content(char **map);
int		validate_map(char **map);
int		is_rectangular(char **map);
int		is_surrounded_by_walls(char **map);
int		ft_strlen(char *s);
void	draw_tile(t_game *game, void *img, int x, int y);
void	draw_map(t_game *game);
void	game_init(t_game *game, char **map);
void	load_images(t_game *game);
void	draw_wall(t_game *game, int x, int y);
void	ft_putchar(char c);
void	ft_putnbr(int n);
int		handle_keypress(int keycode, t_game *game);
void	move_player(t_game *game, int h, int v);
int		exit_game(t_game *game);
void	free_all(t_game *game);
int		update_loop(void *parameter);
char	*ft_itoa(int n);
char	*ft_strjoin(char *s1, char	*s2);
void	display_move_count(t_game *game);
char	*ft_strtrim(char *s, char *set);
char	*join_strings(char *s1, char *s2);
void	free_split(char **split);
int		count_enemies(char **map_2d);
void	enemy_init(t_game *game);
char	*ft_strtrim_for_end(char *s, char *set);
char	**get_2d_array(int fd);
int		get_min_whitespaces(char **map);
void	print_moves(int moves);

#endif