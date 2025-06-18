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
char	**fill_2d_array(char *temp_map);
void	fill_line(char *line, char *temp_map, int *index);
int		is_valid_path(char **map);
int		check_if_unreachable(char **copy);
void	flood_fill(char **map, int x, int y);
char	**copy_map(char **map);
void	find_player(char **map, int *x, int *y);
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
void	draw_background(t_game *game);
void	draw_wall(t_game *game, int x, int y);
void	ft_putchar(char c);
void	ft_putnbr(int n);
int		handle_keypress(int keycode, t_game *game);
void	move_player(t_game *game, int h, int v);
int		exit_game(t_game *game);
void	free_all(t_game *game);
char	*ft_strtrim(char *s, char *set);
char	*ft_strjoin_with_newline(char *s1, char *s2);
char	*clean_map_string(char *temp_map);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strjoin(char *s1, char *s2);
void	get_line_bounds(char **lines, int *start, int *end);
char	*append_trimmed_line(char *cleaned_temp, char *line, char *set);
char	*join_cleaned_lines(char **lines, int start, int end);
void	free_split(char **split);

#endif