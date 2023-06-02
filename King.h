#ifndef KING_H
#define KING_H

#include "Piece.h"

class King : public Piece{
    public:
        King();
        King(int initialFile, int initialRank, bool pieceColor);
        bool move(int newRank, int newFile);
};

#endif