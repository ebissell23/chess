#ifndef KING_H
#define KING_H

#include "Piece.h"

class King : public Piece{
    public:
        King();
        King(int initialFile, int initialRank, bool pieceColor);
        bool move(int newRank, int newFile);
        bool isValidMove(int newRank, int newFile);
        bool capture(int newRank, int newFile);
        bool isValidCapture(int newRank, int newFile);
};

#endif