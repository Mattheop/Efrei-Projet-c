# Répertoires
SRC_DIR = src
OBJ_DIR = out

# Fichiers source
SRCS = $(wildcard $(SRC_DIR)/**/*.c $(SRC_DIR)/*.c)
DEPS = $(wildcard $(SRC_DIR)/**/*.h $(SRC_DIR)/*.h)

CC = gcc
CFLAGS = -I$(SRC_DIR)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
TARGET = main

# Compilation des fichiers sources en fichiers objets
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(DEPS)
	mkdir $(dir $@)
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean run

clean:
	rm -rf $(OBJ_DIR)/*.o
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)
	make clean
