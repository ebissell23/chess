#include "Piece.h"
#include <iostream>


Piece::Piece(){
    file = -1;
    rank = -1;
    color = false;
    hasMoved = false;
    nickName ='-';
}
Piece::Piece(int initialRank, int initialFile, bool pieceColor){
    file = initialFile;
    rank = initialRank;
    color = pieceColor;
}
Piece::~Piece(){}
Piece::Piece(const Piece& other){
    this->file = other.file;
    this->rank = other.rank;
    this->color = other.color;
    this->hasMoved = other.hasMoved;
    this->nickName = other.nickName;
}

char Piece::getNickname(){
    return nickName;
}
void Piece::setNickname(char newNickname){
    nickName = newNickname;
}
bool Piece::isValidMove(int newRank, int newFile){
    std::cout<<" piece isvalidmove " << std::endl;
    return false;
}
bool Piece::move(int newRank, int newFile){
    rank = newRank;
    file=newFile;
    return true;
}
