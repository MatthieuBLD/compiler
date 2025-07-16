# === Variables ===
CC       := gcc
CFLAGS   := -Wall -Wextra -Werror -Iincludes
SRC_DIR  := src
OBJ_DIR  := build/obj
BIN_DIR  := build/out
TARGET   := $(BIN_DIR)/main

SRC      := $(wildcard $(SRC_DIR)/*.c)
OBJ      := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

# === Règles ===
.PHONY: all clean fclean re exec

all: $(TARGET)

$(TARGET): $(OBJ)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

exec: $(TARGET)
	@./$(TARGET)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(BIN_DIR)

re: fclean all