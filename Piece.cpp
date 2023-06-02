#include "Piece.h"

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
bool Piece::move(int newRank, int newFile){
    rank = newRank;
    file=newFile;
    return true;
}
