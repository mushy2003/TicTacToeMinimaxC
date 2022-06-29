CC = clang
CFLAGS = -Wall
BUILD = game

all: $(BUILD)
clean:
	rm -f *.o game

game: minimax.o board.o
minimax.o: minimax.h board.h
board.o: board.h

