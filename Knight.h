#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"

class Knight : public Piece{
    public:
        Knight();
        Knight(int initialFile, int initialRank, bool pieceColor);
        bool move(int newRank, int newFile);
        bool isValidMove(int newRank, int newFile);
};

#endif