CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS =

SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin

# Archivos fuente
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))
MAIN_OBJ = $(BUILD_DIR)/modelokepler.o

# Nombre del ejecutable
EXECUTABLE = $(BIN_DIR)/programa

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS) $(MAIN_OBJ)
	@mkdir -p $(BIN_DIR)
	$(CC) $(LDFLAGS) $^ -o $@ -lm

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)
