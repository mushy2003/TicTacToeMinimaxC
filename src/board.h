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

// Inserts a value into a free position on the board.
void insert_value(board *, char, int, int);

// Removes a value from a position and labels it as empty.
void remove_value(board *, int, int);

// Checks if there is a winner.
bool is_winner(board *, char);

// Checks if there is a winner vertically.
bool is_winner_vertical(board *, char);

// Checks if there is a winner horizontally.
bool is_winner_horizontal(board *, char);

// Checks if there is a winner diagonally.
bool is_winner_diagonal(board *, char);

// Checks if the game is a draw.
bool is_draw(board *);

// Prints the current state of the game grid.
void print_board(board *);

// Switches the character from noughts to crosses and vice-versa.
char switch_player(char);

#endif