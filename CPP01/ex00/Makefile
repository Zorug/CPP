# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/16 22:03:19 by cgross-s          #+#    #+#              #
#    Updated: 2026/05/14 23:46:00 by cgross-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nome do executavel final gerado pelo make.
NAME = BraiiiiiiinnnzzzZ

# Compilador C++ e flags obrigatorias do projeto (padrao C++98).
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Arquivos-fonte e seus respectivos objetos.
SRCS = main.cpp Zombie.cpp randomChump.cpp newZombie.cpp
OBJS = $(SRCS:.cpp=.o)

# Alvo padrao: compila tudo.
all: $(NAME)

# Linka os objetos para gerar o executavel.
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

# Regra generica para compilar qualquer .cpp em .o.
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Remove apenas arquivos objeto.
clean:
	rm -f $(OBJS)

# Remove objetos e executavel final.
fclean: clean
	rm -f $(NAME)

# Recompila do zero.
re: fclean all

# Indica alvos que nao sao arquivos reais.
.PHONY: all clean fclean re
