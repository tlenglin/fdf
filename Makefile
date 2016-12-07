# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/03 16:43:24 by tlenglin          #+#    #+#              #
#    Updated: 2016/12/06 16:52:42 by tlenglin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = display.c main.c create_grid.c create_grid_bis.c projection.c \
		projection_bis.c display_bis.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

FLAGSMLX = -I/usr/local/include/mlx.h -lmlx -framework OpenGL -framework Appkit

CC = gcc

LIBFT_PATH = ./libft

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_PATH)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ) -L./libft -lft $(FLAGSMLX)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ)
	@make -C $(LIBFT_PATH) clean

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
