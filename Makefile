# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oryabchu <oryabchu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/06 11:05:22 by oryabchu          #+#    #+#              #
#    Updated: 2019/04/06 17:40:24 by oryabchu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush00

SRCS = Screen.cpp Hero.cpp Unit.cpp Dron.cpp Projectile.cpp \
		TilePice.cpp TileHeandler.cpp Spawner.cpp CDron.cpp\
		main.cpp BDron.cpp HProjectile.cpp
HDRS = Screen.hpp Hero.hpp Unit.hpp Dron.hpp Projectile.hpp \
		TilePice.hpp TileHeandler.hpp Spawner.cpp CDron.hpp \
		BDron.hpp HProjectile.hpp

OBJECTS = $(SRCS:.cpp=.o)

FLAGS = -std=c++98 -Wall -Werror -Wextra

CC = clang++

all: $(NAME)

$(NAME): $(OBJECTS) $(HDRS)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJECTS)  -lncurses
%.o: %.cpp
	@$(CC) $(FLAGS) -c $<
clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)	

re: fclean all

.PHONY: re all clean fclean