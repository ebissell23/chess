#include "Rook.h"
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

bool Rook::move(int newRank, int newFile){
    //TODO: add checking to see if rook can move there.
    rank = newRank;
    file = newFile;
    return true;
}
bool Rook::isValidMove(int newRank, int newFile){
    return false;
}
bool Rook::capture(int newRank, int newFile){
    return false;
}