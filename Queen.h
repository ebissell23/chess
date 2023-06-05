#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

class Queen : public Piece{
    public:
        Queen();
        Queen(int initialFile, int initialRank, bool pieceColor);
        bool move(int newRank, int newFile);
        bool isValidMove(int newRank, int newFile) override;
};

#endif