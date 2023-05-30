/* 
Author: Erik B.
Let's make some anarchy chess
*/

#include <iostream>
#include <vector>

bool checkMate = false;
const int BOARD_SIZE = 8;


class Chessboard {
    private:
        Piece board[BOARD_SIZE][BOARD_SIZE];
    //constructor
   public Chessboard(){
        //make it empty, then we will add pieces
        for (int i = 0; i < BOARD_SIZE; i++){
            for (int j = 0; j < BOARD_SIZE; j++){
                board[i][j] = NULL;
            }
        }

    }

   public void displayBoard() {
        //shows current state of boardhw
    }

    
}
class Piece{
    protected:
        int file;
        int rank;
        bool color; //true white, false black
        bool hasMoved; //useful for castling and pawn moves
    
    public:
        Piece(int initialFile, int initialRank, bool pieceColor){
            file = initialFile; // x coordinate - A - H
            rank = initialRank; // y coordinate - 1-8
            color = pieceColor;
        }
        virtual void move(int newRank, int newFile){
            rank = newRank;
            file = newFile;
        }

}
//
class Pawn : public Piece {

public:
//constructor
    Pawn(int initialFile, int initialRank, bool pieceColor){
        //in a normal game all pawns would be on 2 or 7 rank
        //will help to have both coordinates to impliment puzzles later
        file = initialFile;
        rank = initialRank;
        hasMoved = false;
        color = pieceColor;
    }

}
class Rook : public Piece{

}
class Bishop : public Piece{

}
class Knight : public Piece{

}
class King : public Piece{

}
class Queen : public Piece{

}

int main(){
//set up the board 
//while !checkMate get next move

while (!checkMate){

}
return 0;
}
