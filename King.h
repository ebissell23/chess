#ifndef KING_H
#define KING_H

#include "Piece.h"

class King : public Piece{
    public:
        King();
        King(int initialFile, int initialRank, bool pieceColor);
        bool move(int newRank, int newFile, Piece* board[][8]);
        bool isValidMove(int newRank, int newFile, Piece* board[][8]);
        bool capture(int newRank, int newFile, Piece* board[][8]);
        bool isValidCapture(int newRank, int newFile, Piece* board[][8]);
};

#endif