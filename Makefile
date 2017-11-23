CC = gcc

CFLAGS = -std=c99 -pedantic -Wall -Wextra -I src/
LDFLAGS = -L/usr/lib/x86_64-linux-gnu -lSDL2
BIN = chip8
SRC_DIR = src/
I_DIR = src/include/
OBJ = $(addprefix $(SRC_DIR),main.o cpu.o)

all: $(BIN)

$(BIN): $(OBJ)
	$(LINK.o) $^ -o $@ ${TEST}

run: $(BIN)
	./$(BIN)

rerun: clean run


debug: CFLAGS += -g
debug: clean $(BIN)

check: $(BIN)
	@echo test

clean:
	rm -rf $(OBJ) $(BIN)

