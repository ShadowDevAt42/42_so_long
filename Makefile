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
CORE_DIR = core/
CORE_PARSING_DIR = core/parsing/
CORE_RENDER_DIR = core/render/
CORE_INIT_DIR = core/init/
CORE_FREE_DIR = core/free/
CORE_GAMEPLAY_DIR = core/gameplay/
CORE_ANIM_DIR = core/anim/
ERROR_DIR = error/

# Source files
SRCS = $(SRC_DIR)main.c \
	$(SRC_DIR)$(CORE_DIR)handle_event.c \
	$(SRC_DIR)$(CORE_DIR)utils_init.c \
	$(SRC_DIR)$(CORE_DIR)utils_render.c \
	$(SRC_DIR)$(CORE_INIT_DIR)core.c \
	$(SRC_DIR)$(CORE_INIT_DIR)static_assets.c \
	$(SRC_DIR)$(CORE_INIT_DIR)anim_assets.c \
	$(SRC_DIR)$(CORE_FREE_DIR)core.c \
	$(SRC_DIR)$(CORE_FREE_DIR)static_assets.c \
	$(SRC_DIR)$(CORE_FREE_DIR)anim_assets.c \
	$(SRC_DIR)$(CORE_RENDER_DIR)render_basic.c \
	$(SRC_DIR)$(CORE_RENDER_DIR)wall_detection.c \
	$(SRC_DIR)$(CORE_RENDER_DIR)wall_render_utils.c \
	$(SRC_DIR)$(CORE_RENDER_DIR)wall_render.c \
	$(SRC_DIR)$(CORE_RENDER_DIR)render_wall_utils.c \
	$(SRC_DIR)$(CORE_RENDER_DIR)render_anim_elements.c \
	$(SRC_DIR)$(CORE_RENDER_DIR)render_ui.c \
	$(SRC_DIR)$(CORE_RENDER_DIR)render.c \
	$(SRC_DIR)$(CORE_PARSING_DIR)map_validate_basic.c \
	$(SRC_DIR)$(CORE_PARSING_DIR)map_validate_elements.c \
	$(SRC_DIR)$(CORE_PARSING_DIR)map_read.c \
	$(SRC_DIR)$(CORE_PARSING_DIR)map_load.c \
	$(SRC_DIR)$(CORE_PARSING_DIR)map_validate_path.c \
	$(SRC_DIR)$(CORE_PARSING_DIR)map_validator.c \
	$(SRC_DIR)$(ERROR_DIR)error_handler.c \
	$(SRC_DIR)$(CORE_ANIM_DIR)update_anim.c \
	$(SRC_DIR)$(CORE_GAMEPLAY_DIR)player.c \
	$(SRC_DIR)$(CORE_GAMEPLAY_DIR)victory.c \

# Object files with new directory
OBJS = $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

# Create necessary object directories
OBJ_DIRS = $(OBJ_DIR) \
	$(OBJ_DIR)$(CORE_PARSING_DIR) \
	$(OBJ_DIR)$(ERROR_DIR) \
	$(OBJ_DIR)$(CORE_RENDER_DIR) \
	$(OBJ_DIR)$(CORE_DIR) \
	$(OBJ_DIR)$(CORE_INIT_DIR) \
	$(OBJ_DIR)$(CORE_FREE_DIR) \
	$(OBJ_DIR)$(CORE_GAMEPLAY_DIR) \
	$(OBJ_DIR)$(CORE_ANIM_DIR)

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

debug: CFLAGS += -g
debug: re
	@echo "Programme compilé avec les symboles de débogage"

re: fclean all

.PHONY: all clean fclean re make_libs create_dirs debug
