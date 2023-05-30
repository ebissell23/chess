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
    
    public:
        Piece(int initialFile, int initialRank){
            file = initialFile; // x coordinate - A - H
            rank = initialRank; // y coordinate - 1-8
        }
        virtual void move(int newRank, int newFile){
            rank = newRank;
            file = newFile;
        }

}
//
class Pawn : public Piece 
private:
    int file; // x coordinate - A-H
    int rank; // y coordinate - 1-8
    bool hasMoved; //use to see if it can go 1 or 2 squares forward. may help with en passant
    // might need to add a promoted tag as well

public:
//constructor
    Pawn(int initialFile, int initialRank){
        //in a normal game all pawns would be on 2 or 7 rank
        //will help to have both coordinates to impliment puzzles later
        file = initialFile;
        rank = initialRank;
        hasMoved = false;
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
