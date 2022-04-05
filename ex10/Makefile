# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/31 20:06:57 by mlormois          #+#    #+#              #
#    Updated: 2022/04/05 07:24:31 by mlormois         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ZCurve

OBJ_DIR	=   ./objs
SRC_DIR = $(shell find srcs -type d)
vpath %.cpp $(foreach dir, $(SRC_DIR), $(dir):)
SRCS	= $(foreach dir, $(SRC_DIR), $(foreach file, $(wildcard $(dir)/*.cpp), $(notdir $(file))))

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:%.cpp=%.o))

CC		=	clang++

FLAGS	=	-Wall -Werror -Wextra

.PHONY : all
all:	$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(FLAGS) -o $(NAME) $(OBJS)

$(OBJ_DIR)/%.o : %.cpp | $(OBJ_DIR)
			$(CC) $(FLAGS) -c $< -o $@

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
