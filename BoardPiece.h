#ifndef BOARDPIECE_H
#define BOARDPIECE_H
#include "Chessboard.h"
#include "Piece.h"

class BoardPiece : public Piece{
    public:
        BoardPiece();
        bool isValidMove(int newRank, int newFile, Piece* board[][8]);
};

#endif