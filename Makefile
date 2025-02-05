# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: your_login <your_login@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/04 10:00:00 by your_login        #+#    #+#             #
#    Updated: 2024/02/04 10:00:00 by your_login       ###   ########.fr       #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

# Path
LIBFT_PATH	= ./libs/libft
MLX_PATH	= ./libs/minilibx-linux

# Flags for libraries
MLX_FLAGS = -L$(MLX_PATH) -lmlx -lXext -lX11
LIBFT_FLAGS = -L$(LIBFT_PATH) -lft

# Directories
SRC_DIR = srcs/
OBJ_DIR = objs/
MAP_DIR = map/
ERROR_DIR = error/
INIT_DIR = init/
RENDER_DIR = render/
EVENT_DIR = event/
PLAYER_DIR = player/

# Source files
SRCS = $(SRC_DIR)main.c \
	$(SRC_DIR)$(INIT_DIR)map_init.c \
	$(SRC_DIR)$(INIT_DIR)init_sprite.c \
	$(SRC_DIR)$(INIT_DIR)init_wall.c \
	$(SRC_DIR)$(INIT_DIR)init_window.c \
	$(SRC_DIR)$(INIT_DIR)init_player.c \
	$(SRC_DIR)$(INIT_DIR)init_collectible.c \
	$(SRC_DIR)$(INIT_DIR)init_exit.c \
	$(SRC_DIR)$(EVENT_DIR)handle_close.c \
	$(SRC_DIR)$(EVENT_DIR)handle_expose.c \
	$(SRC_DIR)$(EVENT_DIR)handle_keypress.c \
	$(SRC_DIR)$(EVENT_DIR)setup_hooks.c \
	$(SRC_DIR)$(PLAYER_DIR)player_movement.c \
	$(SRC_DIR)$(RENDER_DIR)render_wall.c \
	$(SRC_DIR)$(RENDER_DIR)render_player.c \
	$(SRC_DIR)$(RENDER_DIR)render_collectible.c \
	$(SRC_DIR)$(RENDER_DIR)render_exit.c \
	$(SRC_DIR)$(RENDER_DIR)render.c \
	$(SRC_DIR)$(MAP_DIR)map_validate_basic.c \
	$(SRC_DIR)$(MAP_DIR)map_validate_elements.c \
	$(SRC_DIR)$(MAP_DIR)map_read.c \
	$(SRC_DIR)$(MAP_DIR)map_load.c \
	$(SRC_DIR)$(MAP_DIR)map_validate_path.c \
	$(SRC_DIR)$(MAP_DIR)map_validator.c \
	$(SRC_DIR)$(ERROR_DIR)error_handler.c

# Object files with new directory
OBJS = $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

# Create necessary object directories
OBJ_DIRS = $(OBJ_DIR) \
	$(OBJ_DIR)$(MAP_DIR) \
	$(OBJ_DIR)$(ERROR_DIR) \
	$(OBJ_DIR)$(INIT_DIR) \
	$(OBJ_DIR)$(RENDER_DIR) \
	$(OBJ_DIR)$(EVENT_DIR) \
	$(OBJ_DIR)$(PLAYER_DIR)

# Header files
INCLUDES	= -I./includes -I$(LIBFT_PATH)/includes -I$(MLX_PATH)

all: make_libs $(NAME)

make_libs:
	@echo "Making libft..."
	@make -C $(LIBFT_PATH)
	@echo "Making minilibx..."
	@make -C $(MLX_PATH)

$(NAME): create_dirs $(OBJS)
	@echo "Linking so_long..."
	$(CC) $(OBJS) $(MLX_FLAGS) $(LIBFT_FLAGS) -o $(NAME) -lm

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