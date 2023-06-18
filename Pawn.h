#ifndef PAWN_H
#define PAWN_H
#include "Chessboard.h"
#include "Piece.h"
class Chessboard;
class Pawn : public Piece{
    public:
        Pawn();
        Pawn(int initialFile, int initialRank, bool pieceColor);
        bool move(int newRank, int newFile, Chessboard& chessboard);
        bool isValidMove(int newRank, int newFile);
        bool isWhite();
        bool capture(int newRank, int newFile);

};

#endif