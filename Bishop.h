#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop : public Piece{
    public:
        Bishop();
        Bishop(int initialFile, int initialRank, bool pieceColor);
        bool move(int newRank, int newFile);
        bool isValidMove(int newRank, int newFile);
        bool capture(int newRank, int newFile);
};

#endif