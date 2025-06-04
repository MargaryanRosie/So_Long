NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude -Imlx

SRC = src/map/map_utils.c \
	src/map/map.c \
	src/validation/validate_map.c \
	src/validation/validate_map_utils.c \
	src/validation/validate_path.c \
	src/draw_image.c \
	src/draw_image_2.c \
	src/init_mlx.c \
	src/load_images.c \
	src/main.c \
	src/movement/input.c \
	src/utils.c \
	src/free/free.c

OBJ = $(SRC:.c=.o)

MLX = mlx/libmlx.a
MLX_FLAGS = -Lmlx -lmlx -lX11 -lXext -lm         
all: $(NAME)

$(NAME): $(OBJ) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(MLX) $(MLX_FLAGS) -o $(NAME)          

$(MLX):
	$(MAKE) -C mlx                  

%.o: %.c                //any file ending with .o
	$(CC) $(CFLAGS) -c $< -o $@            //-c means only compile, dont link
	                                    // $< means the first dependency of the rule
										//-o $@  means take the output in the file ($@) which is the target(with .o extension)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re