# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/22 16:09:35 by arsiddiq          #+#    #+#              #
#    Updated: 2019/07/28 20:56:57 by arsiddiq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Werror -Wextra
RUSH_0 = colle-00 colle-01 colle-02 colle-03 colle-04
RUSH_00 = colle-00
RUSH_00_SRCS = srcs/rush0/rush00/rush00.c srcs/rush0/rush00/main.c srcs/utilities/ft_atoi.c srcs/utilities/string_utilities.c
RUSH_01 = colle-01
RUSH_01_SRCS = srcs/rush0/rush01/rush01.c srcs/rush0/rush01/main.c srcs/utilities/ft_atoi.c srcs/utilities/string_utilities.c
RUSH_02 = colle-02
RUSH_02_SRCS = srcs/rush0/rush02/rush02.c srcs/rush0/rush02/main.c srcs/utilities/ft_atoi.c srcs/utilities/string_utilities.c
RUSH_03 = colle-03
RUSH_03_SRCS = srcs/rush0/rush03/rush03.c srcs/rush0/rush03/main.c srcs/utilities/ft_atoi.c srcs/utilities/string_utilities.c
RUSH_04 = colle-04
RUSH_04_SRCS = srcs/rush0/rush04/rush04.c srcs/rush0/rush04/main.c srcs/utilities/ft_atoi.c srcs/utilities/string_utilities.c
NAME = colle-2
RUSH_2_SRCS = srcs/main.c srcs/output_analyzer.c srcs/utilities/ft_atoi.c srcs/utilities/string_utilities.c srcs/rush0/rush00/rush00.c srcs/rush0/rush01/rush01.c srcs/rush0/rush02/rush02.c srcs/rush0/rush03/rush03.c srcs/rush0/rush04/rush04.c

all: $(RUSH_0) $(NAME)

$(NAME):
	@gcc $(FLAGS) -o $(NAME) $(RUSH_2_SRCS) -Iincludes

$(RUSH_00):
	@gcc $(FLAGS) -o $(RUSH_00) $(RUSH_00_SRCS) -Iincludes

$(RUSH_01):
	@gcc $(FLAGS) -o $(RUSH_01) $(RUSH_01_SRCS) -Iincludes

$(RUSH_02):
	@gcc $(FLAGS) -o $(RUSH_02) $(RUSH_02_SRCS) -Iincludes

$(RUSH_03):
	@gcc $(FLAGS) -o $(RUSH_03) $(RUSH_03_SRCS) -Iincludes

$(RUSH_04):
	@gcc $(FLAGS) -o $(RUSH_04) $(RUSH_04_SRCS) -Iincludes

fclean: clean
	@rm -f $(NAME)

clean:
	@rm -f $(RUSH_0)

re: fclean all
