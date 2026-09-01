NAME = ex00

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
	$(SRC_DIR)/ScalarConverter.cpp

OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# **************************************************************************** #
# RULES
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re test