NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

# Path
LIBFT_PATH = libft/
MLX_PATH = minilibx-linux/

# Flags for libraries
MLX_FLAGS = -L$(MLX_PATH) -lmlx -lXext -lX11
LIBFT_FLAGS = -L$(LIBFT_PATH) -lft

# Directories
SRC_DIR = srcs/
OBJ_DIR = objs/
CORE_DIR = core/
MAP_DIR = map/
PLAYER_DIR = player/
WINDOW_DIR = window/
UTILS_DIR = utils/
COLLECTIBLE_DIR= collectible/
DOOR_DIR = door/

# Source files
SRCS = $(SRC_DIR)main.c \
	$(SRC_DIR)$(CORE_DIR)game_init.c \
	$(SRC_DIR)$(CORE_DIR)game_loop.c \
	$(SRC_DIR)$(CORE_DIR)game_cleanup.c \
	$(SRC_DIR)$(MAP_DIR)map_reader.c \
	$(SRC_DIR)$(MAP_DIR)map_utils.c \
	$(SRC_DIR)$(PLAYER_DIR)player_init.c \
	$(SRC_DIR)$(PLAYER_DIR)player_movement.c \
	$(SRC_DIR)$(WINDOW_DIR)window_init.c \
	$(SRC_DIR)$(WINDOW_DIR)window_events.c \
	$(SRC_DIR)$(UTILS_DIR)memory_utils.c \
	$(SRC_DIR)$(COLLECTIBLE_DIR)collectible_init.c \
	$(SRC_DIR)$(COLLECTIBLE_DIR)collectible_update.c \
	$(SRC_DIR)$(DOOR_DIR)door_init.c \
	$(SRC_DIR)$(DOOR_DIR)door_update.c
	

# Object files with new directory
OBJS = $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

# Create necessary object directories
OBJ_DIRS = $(OBJ_DIR) \
	$(OBJ_DIR)$(CORE_DIR) \
	$(OBJ_DIR)$(MAP_DIR) \
	$(OBJ_DIR)$(PLAYER_DIR) \
	$(OBJ_DIR)$(WINDOW_DIR) \
	$(OBJ_DIR)$(UTILS_DIR) \
	$(OBJ_DIR)$(COLLECTIBLE_DIR) \
	$(OBJ_DIR)$(DOOR_DIR)

# Header files
INCLUDES = -I$(MLX_PATH) -I$(LIBFT_PATH)includes -Iincludes

all: make_libs $(NAME)

make_libs:
	@echo "Making libft..."
	@make -C $(LIBFT_PATH)
	@echo "Making minilibx..."
	@make -C $(MLX_PATH)

$(NAME): create_dirs $(OBJS)
	@echo "Linking so_long..."
	$(CC) $(OBJS) $(MLX_FLAGS) $(LIBFT_FLAGS) -o $(NAME)

create_dirs:
	@mkdir -p $(OBJ_DIRS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@make -C $(LIBFT_PATH) clean
	@make -C $(MLX_PATH) clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@rm -f $(NAME)
	@rm -f $(MLX_PATH)/libmlx.a
	@rm -f $(MLX_PATH)/libmlx_Linux.a

re: fclean all

.PHONY: all clean fclean re make_libs create_dirs