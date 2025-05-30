BIN_DIR = 	bin
CXX =		c++
CXXFLAGS =	-Wall -Wextra -Werror -pthread -g3 -std=c++17 -Iinc -Iinc/matrix -Iinc/vector -MMD -MP

SRC_DIR = 	src
SRC =		00.cpp \
            01.cpp \
            02.cpp \
            03.cpp \
            04.cpp \
            05.cpp \
            06.cpp \
            07.cpp \
            08.cpp \
            09.cpp \
            10.cpp \
            11.cpp \
            12.cpp \
            13.cpp \
            14.cpp \

SRC :=		$(addprefix $(SRC_DIR)/, $(SRC))

OBJ_DIR = 	obj
OBJ :=		$(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
DEPS :=		$(OBJ:.o=.d)

all: $(BIN_DIR)

$(BIN_DIR): $(OBJ)
	@mkdir -p $(BIN_DIR)
	@for obj in $(OBJ); do \
		filename=$$(basename $$obj .o); \
		$(CXX) $(CXXFLAGS) $$obj -o $(BIN_DIR)/$$filename; \
	done
	@printf "\033[38;5;75mCompilation done\033[0m\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	@printf "\033[38;5;208m$(CXX) $(CXXFLAGS) -c $< -o $@\033[0m\n"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(BIN_DIR)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
