#ifndef BOARD_H_
#define BOARD_H_

#include <stdbool.h>

#define NOUGHT 'O'
#define CROSS 'X'
#define EMPTY ' '
#define VALUES 'OX '

typedef struct board
{
    int height_and_width;
    char **grid;
} board;

// Allocates memory and initialises the board.
board *board_init(int);

// Frees memory associated with the board.
void board_free(board *);

// Checks if the given position is free
bool is_free_position(board *, int, int);

// Inserts a value into a free grid on the board.
void insert_value(board *, char, int, int);

// Checks if the game has ended and if there is a winner.
bool is_winner(board *, char value);

#endif