# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/31 20:06:54 by mlormois          #+#    #+#              #
#    Updated: 2022/03/31 20:07:11 by mlormois         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	SetEvaluation

INC_DIR	=	./incs
OBJ_DIR	=   ./objs
SRC_DIR = $(shell find srcs -type d)
vpath %.cpp $(foreach dir, $(SRC_DIR), $(dir):)
SRCS	= $(foreach dir, $(SRC_DIR), $(foreach file, $(wildcard $(dir)/*.cpp), $(notdir $(file))))

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:%.cpp=%.o))

CC		=	clang++

FLAGS	=	-Wall -Werror -Wextra -g3

.PHONY : all
all:	$(NAME)

$(NAME):	$(OBJS) $(INC_DIR)/*.hpp
			$(CC) $(FLAGS) -o $(NAME) $(OBJS) -I $(INC_DIR)

$(OBJ_DIR)/%.o : %.cpp $(INC_DIR)/*.hpp | $(OBJ_DIR)
			$(CC) $(FLAGS) -c $< -o $@ -I $(INC_DIR)

$(OBJ_DIR) :
	mkdir -p $@

.PHONY : clean
clean:
			rm -rf $(OBJ_DIR)

.PHONY : fclean
fclean:		clean
			rm -f $(NAME)

.PHONY : re
re:			fclean all
