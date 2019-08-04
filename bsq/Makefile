# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/22 16:09:35 by arsiddiq          #+#    #+#              #
#    Updated: 2019/07/31 21:59:56 by arsiddiq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Werror -Wextra
NAME = bsq
UTILITY_SRCS = srcs/utilities/string_utilities.c
MAIN_SRCS = srcs/main.c srcs/file_parsers.c srcs/grid_validators.c srcs/bsq.c
SRCS = $(MAIN_SRCS) $(UTILITY_SRCS)

all: $(RUSH_0) $(NAME)

$(NAME):
	@gcc $(FLAGS) -o $(NAME) $(SRCS) -Iincludes

debug: fclean
	@gcc -o $(NAME) $(SRCS) -Iincludes

norm:
	@norminette includes/* $(SRCS)

fclean: clean
	@rm -f $(NAME)

clean:
	@rm -f bsq.txt

re: fclean all
