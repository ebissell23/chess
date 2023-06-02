//Chessboard.h

#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include "Piece.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "Pawn.h"

class Chessboard{
    private:
        const static int BOARD_SIZE = 8;
        Piece board[BOARD_SIZE][BOARD_SIZE];
    public:
        Chessboard();
        void displayBoard();

};

#endif