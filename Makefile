BIN_DIR = 	bin
CXX =		c++
CXXFLAGS =	-Wall -Iinc -MMD -MP

SRC_DIR = 	src
SRC =		00.cpp \
			01.cpp \

SRC :=		$(addprefix $(SRC_DIR)/, $(SRC))

OBJ_DIR = 	obj
OBJ :=		$(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

all: $(BIN_DIR)

$(BIN_DIR): $(OBJ_DIR)
	mkdir -p $(BIN_DIR)
	for file in $(SRC_DIR)/*.cpp; do \
		filename=$$(basename $$file .cpp); \
		$(CXX) $(CXXFLAGS) -c $$file -o $(OBJ_DIR)/$$filename.o; \
		$(CXX) $(CXXFLAGS) $(OBJ_DIR)/$$filename.o -o $(BIN_DIR)/$$filename; \
	done

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(BIN_DIR)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re