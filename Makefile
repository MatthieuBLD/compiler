# === Variables ===
CC       := gcc
CFLAGS   := -Iincludes
SRC_DIR  := src
INC_DIR  := includes
BUILD_DIR := build
TARGET   := $(BUILD_DIR)/output

# === Directives ===

$(TARGET): $(BUILD_DIR)/main.o $(BUILD_DIR)/operators.o | $(BUILD_DIR)
	$(CC) $(CFLAGS) $^ -o $@

$(BUILD_DIR)/main.o: $(SRC_DIR)/main.c | $(BUILD_DIR)
	$(CC) -c $(CFLAGS) $< -o $@

$(BUILD_DIR)/operators.o: $(SRC_DIR)/operators.c $(INC_DIR)/operators.h | $(BUILD_DIR)
	$(CC) -c $(CFLAGS) $< -o $@

# Crée le dossier build/ s’il n’existe pas
$(BUILD_DIR):
	mkdir -p $@

exec: $(TARGET)
	@./$(TARGET)

clean:
	rm -f $(BUILD_DIR)/*.o $(TARGET)

.PHONY: exec clean
