#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"
class Chessboard;
class Rook : public Piece{
    public:
        Rook();
        Rook(int initialFile, int initialRank, bool pieceColor);
        bool move(int newRank, int newFile, Piece* board[][8]);
        bool isValidMove(int newRank, int newFile, Piece* board[][8]);
        bool capture(int newRank, int newFile, Piece* board[][8]);
        bool isValidCapture(int newRank, int newFile, Piece* board[][8]);
        //bool isWhite();
       // bool isValidMove2(int newRank, int newFile,  Piece* board[][8]);
};

#endif 