# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/03 14:21:40 by fdi-tria          #+#    #+#              #
#    Updated: 2025/02/03 16:16:47 by fdi-tria         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Directories
SRC_DIR = srcs/
OBJ_DIR = objs/

# Source files
SRCS = $(SRC_DIR)ft_printf.c \
	$(SRC_DIR)ft_putchar.c \
	$(SRC_DIR)ft_puthex.c \
	$(SRC_DIR)ft_putnbr.c \
	$(SRC_DIR)ft_putstr.c \
	$(SRC_DIR)ft_putunsigned.c \
	$(SRC_DIR)ft_gnl.c \
	$(SRC_DIR)ft_append_buffer.c \
	$(SRC_DIR)ft_get_fd_node.c \
	$(SRC_DIR)ft_memchr.c \
	$(SRC_DIR)ft_memcpy.c \
	$(SRC_DIR)ft_remove_fd_node.c\
	$(SRC_DIR)ft_strlen.c \
	$(SRC_DIR)ft_calloc.c \
	$(SRC_DIR)ft_bzero.c \


# Object files
OBJS = $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

# Header files
INCLUDES = -Iincludes

all: create_dirs $(NAME)

create_dirs:
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re create_dirs