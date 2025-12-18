NAME = PmergeMe
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD -MP

SRC = main.cpp PmergeMe.cpp
OBJ_DIR = Executables
OBJ = $(SRC:.cpp=.o)
OBJ_PATHS = $(addprefix $(OBJ_DIR)/,$(OBJ))
DEP = $(OBJ_PATHS:.o=.d)

all: $(NAME)

$(NAME): $(OBJ_PATHS)
	$(CXX) $(CXXFLAGS) $(OBJ_PATHS) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEP)

.PHONY: all clean fclean re