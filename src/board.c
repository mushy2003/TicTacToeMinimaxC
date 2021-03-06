#include "board.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

board *board_init(int height_and_width)
{
    board *playing_board = malloc(sizeof(board));
    assert(playing_board != NULL);
    playing_board->height_and_width = height_and_width;

    playing_board->grid = calloc(height_and_width, sizeof(char *));
    assert(playing_board->grid != NULL);
    for (int i = 0; i < height_and_width; i++)
    {
        playing_board->grid[i] = calloc(height_and_width, sizeof(char));
        assert(playing_board->grid[i] != NULL);
    }

    for (int i = 0; i < height_and_width; i++)
    {
        for (int j = 0; j < height_and_width; j++)
        {
            playing_board->grid[i][j] = EMPTY;
        }
    }

    return playing_board;
}

void board_free(board *board)
{
    for (int i = 0; i < board->height_and_width; i++)
    {
        free(board->grid[i]);
    }

    free(board->grid);

    free(board);
}

bool is_free_position(board *board, int row, int col)
{
    assert(row >= 0 && row < board->height_and_width && col >= 0 && col < board->height_and_width);
    return board->grid[row][col] == EMPTY;
}

void insert_value(board *board, char value, int row, int col)
{
    assert(is_free_position(board, row, col));

    board->grid[row][col] = value;
}

void remove_value(board *board, int row, int col)
{
    board->grid[row][col] = EMPTY;
}

bool is_winner(board *board, char value)
{
    return is_winner_vertical(board, value) || is_winner_horizontal(board, value) || is_winner_diagonal(board, value);
}

bool is_winner_vertical(board *board, char value)
{
    char **grid = board->grid;

    for (int j = 0; j < board->height_and_width; j++)
    {
        if (grid[0][j] == value)
        {
            for (int i = 1; i < board->height_and_width; i++)
            {
                if (grid[i - 1][j] != grid[i][j])
                {
                    break;
                }

                if (i == board->height_and_width - 1)
                {
                    return true;
                }
            }
        }
    }

    return false;
}

bool is_winner_horizontal(board *board, char value)
{
    char **grid = board->grid;

    for (int i = 0; i < board->height_and_width; i++)
    {
        if (grid[i][0] == value)
        {
            for (int j = 1; j < board->height_and_width; j++)
            {
                if (grid[i][j - 1] != grid[i][j])
                {
                    break;
                }
                if (j == board->height_and_width - 1)
                {
                    return true;
                }
            }
        }
    }

    return false;
}

bool is_winner_diagonal(board *board, char value)
{
    char **grid = board->grid;
    if (grid[0][0] == value)
    {
        for (int i = 1; i < board->height_and_width; i++)
        {
            if (grid[i - 1][i - 1] != grid[i][i])
            {
                break;
            }
            if (i == board->height_and_width - 1)
            {
                return true;
            }
        }
    }

    if (grid[0][board->height_and_width - 1] == value)
    {
        for (int i = 1; i < board->height_and_width; i++)
        {
            if (grid[i - 1][board->height_and_width - 1 - (i - 1)] != grid[i][board->height_and_width - 1 - i])
            {
                break;
            }

            if (i == board->height_and_width - 1)
            {
                return true;
            }
        }
    }

    return false;
}

bool is_draw(board *board)
{
    char **grid = board->grid;

    for (int i = 0; i < board->height_and_width; i++)
    {
        for (int j = 0; j < board->height_and_width; j++)
        {
            if (grid[i][j] == EMPTY)
            {
                return false;
            }
        }
    }

    return !(is_winner(board, NOUGHT) || is_winner(board, CROSS));
}

void print_board(board *board)
{
    for (int i = 0; i < board->height_and_width; i++)
    {
        for (int j = 0; j < board->height_and_width; j++)
        {
            printf(" %c ", board->grid[i][j]);
        }
        printf("\n");
    }
}

char switch_player(char current_player)
{
    assert(current_player == NOUGHT || current_player == CROSS);
    switch (current_player)
    {
    case (NOUGHT):
        return CROSS;
    case (CROSS):
        return NOUGHT;
    }
}