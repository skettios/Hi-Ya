#include "gameboard.h"
#include <stdlib.h>

int main(int argc, char *argv[])
{
    hy::game_board *board = (hy::game_board *) malloc(sizeof(hy::game_board));

    hy::setup_board(board);
    hy::run_board(board);
    
    return 0;
}
