#include "Chessboard.h"
#include "Piece.h"
#include "BoardPiece.h"
#include <iostream>
#include "Pawn.h"

Chessboard::Chessboard() {
    for(int i = 0; i < BOARD_SIZE; i++){
        for (int j = 0; j < BOARD_SIZE; j++){
                board[i][j] = nullptr;
        }
    }

    // set up board with pieces
    //[rank][file]
    //black major pieces
    board[0][0] = new Rook(0, 0, false);
    board[0][1] = new Knight(0, 1, false);
    board[0][2] = new Bishop(0, 2, false);
    board[0][3] = new Queen(0, 3, false);
    board[0][4] = new King(0, 4, false);
    board[0][5] = new Bishop(0, 5, false);
    board[0][6] = new Knight(0, 6, false);
    board[0][7] = new Rook(0, 7, false);
    //black pawns
     for (int j = 0; j < BOARD_SIZE; j++) {
        board[1][j] = new Pawn(1, j, false);
    }
    //white major pieces
    board[7][0] = new Rook(7, 0, true);
    board[7][1] = new Knight(7, 1, true);
    board[7][2] = new Bishop(7, 2, true);
    board[7][3] = new Queen(7, 3, true);
    board[7][4] = new King(7, 4, true);
    board[7][5] = new Bishop(7, 5, true);
    board[7][6] = new Knight(7, 6, true);
    board[7][7] = new Rook(7, 7, true);
    //white pawns
    for (int j = 0; j < BOARD_SIZE; j++) {
        board[6][j] = new Pawn(6, j, true);
    }
}
//Displays chessboard as it currently is
void Chessboard::displayBoard(){
    for (int i = 0; i < BOARD_SIZE; i++){
        for (int j = 0; j < BOARD_SIZE; j++){
            if(board[i][j] == nullptr){
                std::cout << "-"<<" ";
            }
            else{
            std::cout << board[i][j]->getNickname() << " ";
            }
        }
        std::cout << std::endl;
    }
}
void Chessboard::setPiece(int rank, int file,  Piece& piece){
    delete board[rank][file];
    board[rank][file]= &piece;
}
int Chessboard::rankAsInt(char input){
    int fileNumber = input - '0'; // gives us the int 
    if(fileNumber >= 1 && fileNumber <= 8){ //if not in this range, not valid
        switch (fileNumber){
            case 1:
            return 7;
            case 2:
            return 6;
            case 3:
            return 5;
            case 4:
            return 4;
            case 5:
            return 3;
            case 6:
            return 2;
            case 7:
            return 1;
            case 8:
            return 0;
            default:
            return -1;

        }
    }
    else{
        return -1;
    }

}
int Chessboard::fileAsInt(char input){
    switch(input) {
        case 'a':
        case 'A':
        return 0;
        break;
        case 'b':
        case 'B':
        return 1;
        break;
        case 'c':
        case 'C':
        return 2;
        break;
        case 'd':
        case 'D':
        return 3;
        break;
        case 'e':
        case 'E':
        return 4;
        break;
        case 'f':
        case 'F':
        return 5;
        break;
        case 'g':
        case 'G':
        return 6;
        break;
        case 'h':
        case 'H':
        return 7;
        break;
        default:
            return -1;
    }
}
//takes input decides if input is valid
void Chessboard::returnRankFile(std::string input){
    int file = fileAsInt(input[0]);
    int rank = rankAsInt(input[1]);
    std::cout << "Rank: " << rank << std::endl;
    std::cout << "File: " << file << std::endl;
}
bool Chessboard::isValidInput(std::string input){
    int length = input.length();
    if ( length == 5){ //format is e4xe5
        std::cout << "in 5" << std::endl;
        if(input[2] != 'x'){
            return false;
        }
        int startFile = fileAsInt(input[0]);
        int startRank = rankAsInt(input[1]);
        int attemptedEndFile = fileAsInt(input[3]);
        int attemptedEndRank = rankAsInt(input[4]);
        if( (board[startRank][startFile] == nullptr) || (board[attemptedEndRank][attemptedEndFile] == nullptr) ){ // can't capture on empty squares
            std::cout << "cant capture on empty square" << std::endl;
            return false;
        }
        std::cout << "calling capture from chessboard" << std::endl;
        return capture(startRank, startFile, attemptedEndRank, attemptedEndFile);    
    }
    if (length != 4){ //can only be 4 characters ex. "e2e4"
        std::cout << input << "is not a valid input, please try again"<<std::endl;
        return false;
    }
    //converts the char to to the representative number on the 2d array
    int startFile = fileAsInt(input[0]);
    int startRank = rankAsInt(input[1]);
    int attemptedEndFile = fileAsInt(input[2]);
    int attemptedEndRank = rankAsInt(input[3]);
    
   

    //Piece& piece = board[startRank][startFile];
    std::cout<<"about to call isvalidMove" << std::endl;
    
    //checks if there is a piece at new spot. will have captures elsewhere
    if ((board[attemptedEndRank][attemptedEndFile]==nullptr) && board[startRank][startFile]->isValidMove(attemptedEndRank,attemptedEndFile)){
        move(startRank,startFile,attemptedEndRank,attemptedEndFile);
    }
    else{
        std::cout << "That move cannot be made -- " <<std::endl;
        return false;
    }
    return true;
}
bool Chessboard::move(int currRank, int currFile, int newRank, int newFile){
    board[newRank][newFile] = board[currRank][currFile];
    board[currRank][currFile] = nullptr;
    return true;
}
bool Chessboard::capture(int currRank, int currFile, int newRank, int newFile){
    if(board[currRank][currFile]->capture(newRank,newFile)){
        delete board[newRank][newFile];
        board[newRank][newFile] = board[currRank][currFile];
        board[currRank][currFile] = nullptr;
        return true;
    }
    return false;
}



     //std::cout << "validInput func "<< std::endl;
    //std::cout << "Rank: " << startRank << std::endl;
    //std::cout << "File: " << startFile << std::endl;
    //std::cout << "EndRank: " << attemptedEndRank << std::endl;
    //std::cout << "EndFile: " << attemptedEndFile << std::endl;
