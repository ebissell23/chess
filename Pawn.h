#ifndef PAWN_H
#define PAWN_H
#include "Chessboard.h"
#include "Piece.h"
class Chessboard;
class Pawn : public Piece{
    public:
        Pawn();
        Pawn(int initialFile, int initialRank, bool pieceColor);
        bool move(int newRank, int newFile, Piece* board[][8]);
        bool isValidMove(int newRank, int newFile, Piece* board[][8]);
        bool isWhite();
        bool isValidCapture(int newRank, int newFile, Piece* board[][8]);
        bool capture(int newRank, int newFile, Piece* board[][8]);

};

#endif