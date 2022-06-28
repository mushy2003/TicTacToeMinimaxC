#include "board.h"
#include "minimax.h"

int minimax(board *board, char value)
{
    if (is_winner(board, value) && value == CROSS)
    {
        return 1;
    }

    if (is_winner(board, value) && value == NOUGHT)
    {
        return -1;
    }

    if (is_draw(board))
    {
        return 0;
    }

    if (value == CROSS)
    {
        int best_score = -1;
        for (int i = 0; i < board->height_and_width; i++)
        {
            for (int j = 0; j < board->height_and_width; j++)
            {
                if (is_free_position(board, i, j))
                {
                    insert_value(board, CROSS, i, j);
                    int score = minimax(board, switch_player(value));
                    remove_value(board, i, j);
                    best_score = (score > best_score) ? score : best_score;
                }
            }
        }

        return best_score;
    }
    else
    {
        int best_score = 1;
        for (int i = 0; i < board->height_and_width; i++)
        {
            for (int j = 0; j < board->height_and_width; j++)
            {
                if (is_free_position(board, i, j))
                {
                    insert_value(board, NOUGHT, i, j);
                    int score = minimax(board, switch_player(value));
                    remove_value(board, i, j);
                    best_score = (score < best_score) ? score : best_score;
                }
            }
        }

        return best_score;
    }
}

void play_best_move(board *board, char value)
{
    int best_score = -1;
    int best_row, best_col;
    for (int i = 0; i < board->height_and_width; i++)
    {
        for (int j = 0; j < board->height_and_width; j++)
        {
            if (is_free_position(board, i, j))
            {
                insert_value(board, value, i, j);
                int score = minimax(board, switch_player(value));
                remove_value(board, i, j);
                if (score > best_score)
                {
                    best_row = i;
                    best_col = j;
                    best_score = score;
                }
            }
        }
    }

    insert_value(board, value, best_row, best_col);
}