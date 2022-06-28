#include "minimax.h"
#include "board.h"
#include <stdio.h>
#include <assert.h>

int main(void)
{

    int height_and_width = 3;

    board *board = board_init(height_and_width);

    while (!(is_winner(board, NOUGHT) || is_winner(board, CROSS) || is_draw(board)))
    {
        int row, col;
        do
        {
            printf("Player's turn, please enter the row, with 1 being first and %d being last: ", height_and_width);
            int read;
            read = scanf("%d", &row);
            assert(read == 1);
            printf("Enter column: ");
            read = scanf("%d", &col);
            assert(read == 1);
        } while (row > height_and_width || row <= 0 || col > height_and_width || col <= 0 || !is_free_position(board, row - 1, col - 1));

        insert_value(board, NOUGHT, row - 1, col - 1);

        printf("Current status of the board...\n");

        print_board(board);

        if (is_winner(board, NOUGHT) || is_draw(board))
        {
            break;
        }

        printf("Computer taking it's turn...\n");

        play_best_move(board, CROSS);

        printf("Current status of the board...\n");

        print_board(board);
    }

    if (is_winner(board, NOUGHT))
    {
        printf("CONGRATULATIONS! You win!\n");
    }
    else if (is_winner(board, CROSS))
    {
        printf("UNLUCKY! The Computer has won!\n");
    }
    else
    {
        printf("It's a tie!\n");
    }

    board_free(board);

    return 0;
}