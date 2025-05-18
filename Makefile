# === CONFIGURATION ===
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g --pedantic -W -Wmissing-prototypes
LDFLAGS = -lraylib -lm -ldl -lpthread -lrt -lX11
SRC_DIR = src
OBJ_DIR = objects
BIN_DIR = bin
TARGET = $(BIN_DIR)/mandelbroot

# === SOURCES & OBJECTS ===
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# === RULES ===
all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)/*.o
	rm -f $(TARGET)

run: all
	./$(TARGET)
