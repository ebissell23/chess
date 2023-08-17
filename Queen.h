#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

class Queen : public Piece{
    public:
        Queen();
        Queen(int initialFile, int initialRank, bool pieceColor);
        bool move(int newRank, int newFile, Piece* board[][8]);
        bool isValidMove(int newRank, int newFile, Piece* board[][8]);
        bool capture(int newRank, int newFile, Piece* board[][8]);
        bool isValidCapture(int newRank, int newFile, Piece* board[][8]);
};

#endif