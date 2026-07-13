NAME = maggots

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
	$(SRC_DIR)/Bureaucrat.cpp \
	$(SRC_DIR)/Form.cpp

OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# **************************************************************************** #
# HEADERS
# **************************************************************************** #

HEADERS = \
	Bureaucrat.hpp \ 
	Form.hpp

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