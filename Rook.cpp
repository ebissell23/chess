#include "Rook.h"
#include <iostream>
Rook::Rook(){
    file = -1;
    rank = -1;
    color = false;
    hasMoved = false;
    nickName = 'R';
}
Rook::Rook(int initialRank, int initialFile, bool pieceColor){
    file = initialFile;
    rank = initialRank;
    color = pieceColor;
    hasMoved = false;
    nickName='R';
}

bool Rook::move(int newRank, int newFile, Piece* board[][8]){
   if(isValidMove(newRank, newFile,board)){
        rank = newRank;
        file = newFile;
        return true;
    }
    return false;
}
bool Rook::isValidMove(int newRank, int newFile, Piece* board[][8]){
    std::cout <<"rook isValid Move" << std::endl;

    return false;
}
bool Rook::capture(int newRank, int newFile, Piece* board[][8]){
    if(isValidCapture(newRank, newFile,board)){
        rank = newRank;
        file = newFile;
        return true;
    }
    return false;
}
bool Rook::isValidCapture(int newRank, int newFile, Piece* board[][8]){
    return false;
}
//bool Rook::isValidMove2(int newRank, int newFile,  Piece* board[][8]){
  //  std::cout << " Rook validmove 2" << std::endl;
    //return false;
//}