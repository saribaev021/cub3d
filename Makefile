# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ndreadno <ndreadno@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/23 17:38:21 by ndreadno          #+#    #+#              #
#    Updated: 2020/07/31 16:13:11 by ndreadno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
SOURCES = main.c
#OBJECTS = $(SOURCES:.c=.o)
FLAGS = -Wall -Wextra -Werror
all: $(SOURCES)
	cc -g -I /usr/local/include $(SOURCES) -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit -o $(NAME)
clean:
	@rm -f *.o
fclean: clean
	@rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re