#include "Bishop.h"
Bishop::Bishop(){
    file = -1;
    rank = -1;
    color = false;
    hasMoved = false;
    nickName = 'Q';
}
Bishop::Bishop(int initialRank, int initialFile, bool pieceColor){
    file = initialFile;
    rank = initialRank;
    color = pieceColor;
    hasMoved = false;
    nickName='B';
}

bool Bishop::move(int newRank, int newFile){
    //TODO: add checking to see if Bishop can move there.
    rank = newRank;
    file = newFile;
    return true;
}
bool Bishop::isValidMove(int newRank, int newFile){
    return false;
}