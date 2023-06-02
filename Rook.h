#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

class Rook : public Piece{
    public:
        Rook();
        Rook(int initialFile, int initialRank, bool pieceColor);
        bool move(int newRank, int newFile);
};

#endif