#ifndef MINIMAX_H_
#define MINIMAX_H_

#include <stdbool.h>
#include "board.h"

int minimax(board *, char);

void play_best_move(board *, char);

#endif