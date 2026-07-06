NAME = IDWSWFire

# **************************************************************************** #
# COMPILER
# **************************************************************************** #

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# **************************************************************************** #
# SOURCES
# **************************************************************************** #

SRC_DIR = src
OBJ_DIR = obj

SRCS = \
	$(SRC_DIR)/main.cpp \
	$(SRC_DIR)/Animal.cpp \
	$(SRC_DIR)/Dog.cpp \
	$(SRC_DIR)/Cat.cpp \
	$(SRC_DIR)/WrongAnimal.cpp \
	$(SRC_DIR)/WrongCat.cpp \
	$(SRC_DIR)/Brain.cpp

OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# **************************************************************************** #
# HEADERS
# **************************************************************************** #

HEADERS = \
	Animal.hpp \
	Dog.hpp \
	Cat.hpp \
	WrongAnimal.hpp \
	WrongCat.hpp

# **************************************************************************** #
# RULES
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

#%.o: %.cpp $(HEADERS)
#	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: $(NAME)
	./$(NAME)

.PHONY: all clean fclean re test