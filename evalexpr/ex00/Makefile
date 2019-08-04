# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/22 16:09:35 by arsiddiq          #+#    #+#              #
#    Updated: 2019/07/27 19:14:22 by arsiddiq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Werror -Wextra
NAME = eval_expr
SRCS = srcs/main.c srcs/ft_atoi.c srcs/ft_evaluator.c srcs/ft_itoa.c srcs/ft_math_utilities.c srcs/ft_putnbr.c srcs/ft_split_whitespaces.c srcs/ft_string_utilities.c
OBJS = main.o ft_atoi.o ft_evaluator.o ft_itoa.o ft_math_utilities.o ft_putnbr.o ft_split_whitespaces.o ft_string_utilities.o

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