#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <../mlx/mlx.h>

#define TILE_SIZE 32

typedef struct s_game
{
	void	*mlx;              //returned from mlx_init()
	void	*window;          //created with mlx_new_window()
	char	**map;
	int		width;
	int 	height;
	int		player_x;
	int		player_y;
	int		moves;
	int		collectibles;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_exit;
	void	*img_collectible;
} t_game;

int		count_lines(char *temp_map);
int		line_length(char *temp_map);
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
static void	set_flags(char c, int *col, int *wall, int *space);
int		has_basic_components(char **map);
static void	count_elements(char ch, int *c, int *p, int *e);
int		has_valid_num_of_elements(char **map);
int		validate_structure(char **map);
int		validate_content(char **map);
int		validate_map(char **map);
int		is_rectangular(char **map);
int		is_surrounded_by_walls(char **map);
int		ft_strlen(char *s);
void	draw_tile(t_game *game, void *img, int x, int y);
void	draw_map(t_game *game);
static void set_game_state(t_game *game);
void	game_init(t_game *game, char **map);
void	load_images(t_game *game);

#endif