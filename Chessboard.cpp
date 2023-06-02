#include "Chessboard.h"
#include "Piece.h"
#include <iostream>

Chessboard::Chessboard() {
    for(int i = 0; i < BOARD_SIZE; i++){
        for (int j = 0; j < BOARD_SIZE; j++){
                board[i][j] = Piece();
        }
    }

    // set up board with pieces
    // [rank][file]
    //black major pieces
    Rook ra8(0,0,false);
    board[0][0] = ra8;
    Knight nb8(0,1,false);
    board[0][1] = nb8;
    Bishop bc8(0,3,false);
    board[0][2] = bc8;
    Queen qd8(0,4,false);
    board[0][3] = qd8;
    King ke8(0,5,false);
    board[0][4] = ke8;
    Bishop bf8(0,6,false);
    board[0][5] = bf8;
    Knight ng8(0,6,false);
    board[0][6] = ng8;
    Rook rh8(0,7,false);
    board[0][7] = rh8;
    //black pawns
    Pawn pa7(1,0,false);
    board[1][0] = pa7;
    Pawn pb7(1,1,false);
    board[1][1] = pb7;
    Pawn pc7(1,2,false);
    board[1][2] = pc7;
    Pawn pd7(1,3,false);
    board[1][3] = pd7;
    Pawn pe7(1,4,false);
    board[1][4] = pe7;
    Pawn pf7(1,5,false);
    board[1][5] = pf7;
    Pawn pg7(1,6,false);
    board[1][6] = pg7;
    Pawn ph7(1,7,false);
    board[1][7] = ph7;
    //white major pieces
    Rook ra1(7,0,true);
    board[7][0] = ra1;
    Knight nb1(7,1,true);
    board[7][1] = nb1;
    Bishop bc1(7,3,true);
    board[7][2] = bc1;
    Queen qd1(7,4,true);
    board[7][3] = qd1;
    King ke1(7,5,true);
    board[7][4] = ke1;
    Bishop bf1(7,6,true);
    board[7][5] = bf1;
    Knight ng1(7,6,true);
    board[7][6] = ng1;
    Rook rh1(7,7,true);
    board[7][7] = rh1;
    //white pawns
    Pawn pa2(6,0,true);
    board[6][0] = pa2;
    Pawn pb2(6,1,true);
    board[6][1] = pb2;
    Pawn pc2(6,2,true);
    board[6][2] = pc2;
    Pawn pd2(6,3,true);
    board[6][3] = pd2;
    Pawn pe2(6,4,true);
    board[6][4] = pe2;
    Pawn pf2(6,5,true);
    board[6][5] = pf2;
    Pawn pg2(6,6,true);
    board[6][6] = pg2;
    Pawn ph2(6,7,true);
    board[6][7] = ph2;
}
//Displays chessboard as it currently is
void Chessboard::displayBoard(){
    for (int i = 0; i < BOARD_SIZE; i++){
        for (int j = 0; j < BOARD_SIZE; j++){
            std::cout << board[i][j].getNickname() << " ";
        }
        std::cout << std::endl;
    }
}
void Chessboard::setPiece(int rank, int file, const Piece& piece){
    board[rank][file]=piece;
}
//takes input decides if input is valid
bool Chessboard::isValidInput(std::string input){
    int length = input.length();
    if (length != 4){ //can only be 4 characters ex. "e2e4"
        std::cout << input << "is not a valid input, please try again"<<std::endl;
        return false;
    }
    char firstChar = input[0];
    char secondChar = input[1];
    char thirdChar = input[2];
    char fourthChar = input[3];
    int startFile;
    int startRank;
    int attemptedEndFile;
    int attemptedEndRank;
    //converts the char to to the representative number on the 2d array
    switch(firstChar) {
        case 'a':
        case 'A':
        startFile = 0;
        break;
        case 'b':
        case 'B':
        startFile = 1;
        break;
        case 'c':
        case 'C':
        startFile = 2;
        break;
        case 'd':
        case 'D':
        startFile = 3;
        break;
        case 'e':
        case 'E':
        startFile = 4;
        break;
        case 'f':
        case 'F':
        startFile = 5;
        break;
        case 'g':
        case 'G':
        startFile = 6;
        break;
        case 'h':
        case 'H':
        startFile = 7;
        break;
        default:
            return false;
    }
    int secondCharAsNumber = secondChar - '0'; // gives us the int 
    if(secondCharAsNumber >= 1 && secondCharAsNumber <= 8){ //if not in this range, not valid
        startRank = secondCharAsNumber - 1; 
    }
    else{
        return false;
    }
    switch(thirdChar) {
        case 'a':
        case 'A':
        attemptedEndFile = 0;
        break;
        case 'b':
        case 'B':
        attemptedEndFile = 1;
        break;
        case 'c':
        case 'C':
        attemptedEndFile = 2;
        break;
        case 'd':
        case 'D':
        attemptedEndFile = 3;
        break;
        case 'e':
        case 'E':
        attemptedEndFile = 4;
        break;
        case 'f':
        case 'F':
        attemptedEndFile = 5;
        break;
        case 'g':
        case 'G':
        attemptedEndFile = 6;
        break;
        case 'h':
        case 'H':
        attemptedEndFile = 7;
        break;
        default:
            return false;
    }
    int fourthCharAsNumber = fourthChar - '0';
    if(fourthCharAsNumber >= 1 && fourthCharAsNumber <= 8){
        attemptedEndRank = fourthCharAsNumber - 1; 
    }
    else{
        return false;
    }

    board[startRank][startFile].move(attemptedEndFile, attemptedEndRank);
    return true;
}



    
