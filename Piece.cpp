#include "Piece.h"
#include <iostream>


Piece::Piece(){
    file = -1;
    rank = -1;
    color = false;
    hasMoved = false;
    nickName ='-';
}
Piece::Piece(int initialFile, int initialRank, bool pieceColor){
    file = initialFile;
    rank = initialRank;
    color = pieceColor;
}

char Piece::getNickname(){
    return nickName;
}
void Piece::setNickname(char newNickname){
    nickName = newNickname;
}
bool Piece::isValidMove(int newRank, int newFile){
    std::cout<<"piece isvalidmove" << std::endl;
    return false;
}
bool Piece::move(int newRank, int newFile){
    rank = newRank;
    file=newFile;
    return true;
}
