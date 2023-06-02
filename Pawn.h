#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

class Pawn : public Piece{
    public:
        Pawn();
        Pawn(int initialFile, int initialRank, bool pieceColor);
        bool move(int newRank, int newFile);
};

#endif