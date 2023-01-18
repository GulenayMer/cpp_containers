# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgulenay <mgulenay@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/19 11:02:38 by mgulenay          #+#    #+#              #
#    Updated: 2023/01/18 16:31:42 by mgulenay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_cont

CC = g++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = 	vector_test.cpp \
#std_func_test.cpp
#iterator_test.cpp
#map_test.cpp


OBJ	= $(SRC:%.cpp=%.o)

all: $(NAME)

RM = rm -f

$(OBJ): %.o: %.cpp	
		$(CC) -c $(FLAGS) $< -o $@


$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)



clean:
		$(RM) $(OBJ)

fclean:		clean
				$(RM) $(NAME)
			
re: 		fclean all
