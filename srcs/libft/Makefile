# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ndreadno <ndreadno@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/12 18:43:36 by ndreadno          #+#    #+#              #
#    Updated: 2020/08/23 15:03:14 by ndreadno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
OBJ  = ft_memcmp.o ft_memset.o ft_memcpy.o ft_memmove.o ft_isalnum.o ft_isalpha.o \
	ft_isascii.o ft_isdigit.o ft_isprint.o ft_memccpy.o ft_memchr.o ft_strchr.o \
	ft_strdup.o ft_strlcat.o ft_strlcpy.o ft_strlen.o ft_strncmp.o ft_strnstr.o \
	ft_strrchr.o ft_substr.o ft_tolower.o ft_toupper.o ft_bzero.o ft_atoi.o \
	ft_calloc.o ft_strjoin.o ft_strtrim.o ft_split.o ft_itoa.o ft_strmapi.o \
	ft_putchar_fd.o ft_putstr_fd.o ft_putnbr_fd.o ft_putendl_fd.o\
	ft_get_next_line.o ft_space.o ft_skip_digit.o

INCLUDES = ./
FLAGS = -Wall -Wextra -Werror
all: $(NAME)
$(NAME):$(OBJ)
	ar rc $(NAME) $?
	ranlib $(NAME)
%.o:%.c
	gcc $(FLAGS) -I $(INCLUDES) -c $< -o $@
clean:
	/bin/rm -f $(OBJ)
fclean:clean
	/bin/rm -f $(NAME)
re:fclean all
