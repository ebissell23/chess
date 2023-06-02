//Chessboard.h

#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include <string>
#include "Piece.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "Pawn.h"
class Pawn;
class Chessboard{
    private:
        const static int BOARD_SIZE = 8;
        Piece board[BOARD_SIZE][BOARD_SIZE];
    public:
        Chessboard();
        void displayBoard();
        bool isValidInput(std::string input);
        void setPiece(int rank, int file, const Piece& piece);
        int rankAsInt(char input);
        int fileAsInt(char input);

};

#endif