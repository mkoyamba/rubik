# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/06 17:04:20 by mkoyamba          #+#    #+#              #
#    Updated: 2023/06/29 16:30:41 by mkoyamba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#          ----------========== {     VARS     } ==========----------

NAME = rubik
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
INCLUDE = -I includes

#          ----------========== {     SRCS     } ==========----------

SRC_DIR = srcs

#MAIN
SRC =	main.cpp\

#MANDATORY
SRC += madatory/parsing.cpp\

#BONUS
SRC +=	bonus/open.cpp\

#          ----------========== {     OBJS     } ==========----------

OBJ_DIR = obj_dir/
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

VPATH= $(shell find ./ -type d)

#          ----------========== {    REGLES    } ==========----------

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o: %.cpp
	@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@
	@printf "\e[1;42m \e[0;m"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -f $(OBJ)
	@rm -rf obj_dir
	@printf "\e[0;31m[.o files deleted]\n\e[0;m"

fclean: clean
	@rm -f $(NAME)
	@printf "\e[0;31m[rubik deleted]\n\e[0;m"

re: fclean all

.PHONY: all clean fclean re bonus