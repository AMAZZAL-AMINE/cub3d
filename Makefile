# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/17 12:13:49 by mamazzal          #+#    #+#              #
#    Updated: 2023/09/13 12:14:17 by mamazzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = cub3D

GNLN = ./gnln/get_next_line.c ./gnln/get_next_line_utils.c

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

SRC = cub3D.c ./libft_utils/ft_split.c ./parsing/parsing.c read_map.c \
			parsing/check_nswe.c parsing/check_rgb.c \
			free_double.c parsing/check_valid_map.c \
			./parsing/check_rgb_utilis.c ./parsing/parsing_split_line_function.c \
			./libft_utils/str_cmp.c ./mlx_utils/draw_map.c ./libft_utils/libft_utils.c ./mlx_utils/hook.c \
			./mlx_utils/mlx_init.c dupl_map.c ./parsing/check_content_of_map.c ./mlx_utils/moves.c create_rgb.c \
			./mlx_utils/draw_ceil_floor.c draw_mini_map.c errors.c ./mlx_utils/check_vertical_and_herozintal.c \
			./mlx_utils/draw_pixel.c ./mlx_utils/raycasting.c

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS= -Wall -Wextra -Werror  -fsanitize=address -g -Ofast -O3

all: $(NAME)

run :
	make re && ./cub3D maps/map.cub

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJ) $(GNLN)  -o $(NAME)
	@echo "\033[32m[ ✔ ] cub3D"

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
