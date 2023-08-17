# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/17 12:13:49 by mamazzal          #+#    #+#              #
#    Updated: 2023/08/17 13:22:34 by mamazzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME=cub3D

SRC= cub3D.c ft_split.c

OBJ= $(SRC:.c=.o)

FLAGS= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@gcc $(FLAGS) -o $(NAME) $(OBJ) ./gnln/*.c -lmlx -framework OpenGL -framework AppKit
	@echo "\033[32m[ ✔ ] cub3D"

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all