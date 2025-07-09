NAME = so_long
NAME_BONUS = so_long_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude -Imlx
## valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose

SRC = src/map/read_map.c \
	src/map/checking_utils.c \
	src/validation/validate_map.c \
	src/validation/validate_map_utils.c \
	src/validation/validate_path_utils.c \
	src/validation/validate_path.c \
	src/draw_image.c \
	src/draw_image_2.c \
	src/init_mlx.c \
	src/load_images.c \
	src/main.c \
	src/movement/input.c \
	src/movement/player_movement.c \
	src/utils.c \
	src/free/free.c \
	src/map/ft_split_utils.c \
	src/map/ft_split.c \
	src/map/ft_strtrim.c \
	get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c \
	src/map/ft_strjoin.c 


OBJ = $(SRC:.c=.o)

SRC_BONUS = src_bonus/map_bonus/read_map_bonus.c \
 	src_bonus/map_bonus/checking_utils_bonus.c \
	src_bonus/validation_bonus/validate_map_bonus.c \
	src_bonus/validation_bonus/validate_path_bonus.c \
	src_bonus/validation_bonus/validate_path_utils_bonus.c \
	src_bonus/validation_bonus/validate_map_utils_bonus.c \
	src_bonus/free_bonus/free_map_bonus.c \
	src_bonus/init_mlx_bonus.c \
	src_bonus/movement_bonus/movement_bonus.c \
	src_bonus/movement_bonus/player_movement_bonus.c \
	src_bonus/draw_image_bonus.c \
	src_bonus/main_bonus.c \
	src_bonus/init_enemy.c \
	src_bonus/movement_bonus/input_bonus.c \
	src_bonus/utils_bonus.c \
	src_bonus/load_images_bonus.c \
	src_bonus/screen/display_move_count.c \
	src_bonus/map_bonus/ft_split.c \
	src_bonus/map_bonus/ft_split_utils.c \
	src_bonus/map_bonus/ft_strtrim.c \
	src_bonus/map_bonus/ft_strjoin.c \
	get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c

OBJ_BONUS = $(SRC_BONUS:.c=.o)

MLX = mlx/libmlx.a
MLX_FLAGS = -Lmlx -lmlx -lX11 -lXext -lm     
    
all: $(NAME)

$(NAME): $(OBJ) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(MLX) $(MLX_FLAGS) -o $(NAME)  

$(NAME_BONUS): $(OBJ_BONUS) $(MLX)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(MLX) $(MLX_FLAGS) -o $(NAME_BONUS)  

bonus: $(NAME_BONUS)

$(MLX):
	$(MAKE) -C mlx                  

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	make -C mlx clean

re: fclean all

.PHONY: all clean fclean re bonus