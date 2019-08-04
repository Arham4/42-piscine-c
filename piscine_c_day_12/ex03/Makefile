# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/22 16:09:35 by arsiddiq          #+#    #+#              #
#    Updated: 2019/07/25 22:34:08 by arsiddiq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Werror -Wextra
NAME = ft_hexdump
SRCS = srcs/main.c srcs/ft_utilities.c
OBJS = main.o ft_utilities.o

all: $(NAME)

$(NAME): bin
	gcc -o $(NAME) $(OBJS)

bin:
	gcc $(FLAGS) -c $(SRCS) -Iincludes

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all