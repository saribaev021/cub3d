# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ndreadno <ndreadno@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/23 17:38:21 by ndreadno          #+#    #+#              #
#    Updated: 2020/08/26 20:18:37 by ndreadno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
HEADER = srcs/cub3d.h
SOURCES := srcs/main.c srcs/bmp.c srcs/parser/parse.c srcs/parser/parse_parameter.c \
			srcs/parser/errors.c srcs/parser/flag.c srcs/parser/get_file.c srcs/parser/init.c \
			srcs/player.c srcs/parser/add_space_map.c srcs/parser/parse_map.c \
			srcs/parser/check_validation_map.c srcs/raycasting/raycasting.c \
			srcs/raycasting/raycasting_h.c srcs/raycasting/raycasting_up_right_down_left.c \
			srcs/sprites/add_sort_sprites.c srcs/sprites/sprites.c  srcs/sprites/collected_sp_get_sp_color.c \
			srcs/draw_wall.c srcs/paint_2d.c srcs/images.c srcs/paint_3d.c

OBJ := srcs/main.o srcs/bmp.o srcs/parser/parse.o srcs/parser/parse_parameter.o \
			srcs/parser/errors.o srcs/parser/flag.o srcs/parser/get_file.o srcs/parser/init.o \
			srcs/player.o srcs/parser/add_space_map.o srcs/parser/parse_map.o \
			srcs/parser/check_validation_map.o srcs/raycasting/raycasting.o \
			srcs/raycasting/raycasting_h.o srcs/raycasting/raycasting_up_right_down_left.o \
			srcs/sprites/add_sort_sprites.o srcs/sprites/sprites.o  srcs/sprites/collected_sp_get_sp_color.o \
			srcs/draw_wall.o srcs/paint_2d.o srcs/images.o srcs/paint_3d.o

FLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJ)
	cc $(FLAGS) -I $(HEADER) $(OBJ)  libft.a libmlx.dylib -framework OpenGL -framework AppKit -o $(NAME)
%.o: %.c
	gcc $(FLAGS) -c $< -o $@
lib:
	$(MAKE) -C srcs/libft
	$(MAKE) -C mlx
clean:
	$(MAKE) -C srcs/libft clean
	$(MAKE) -C mlx clean
	@rm -f $(OBJ)
fclean: clean
	@rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re