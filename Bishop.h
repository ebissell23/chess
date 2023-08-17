#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop : public Piece{
    public:
        Bishop();
        Bishop(int initialFile, int initialRank, bool pieceColor);
        bool move(int newRank, int newFile, Piece* board[][8]);
        bool isValidMove(int newRank, int newFile, Piece* board[][8]);
        bool capture(int newRank, int newFile, Piece* board[][8]);
        bool isValidCapture(int newRank, int newFile, Piece* board[][8]);
};

#endif