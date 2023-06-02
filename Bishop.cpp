#include "Bishop.h"
Bishop::Bishop(){
    file = -1;
    rank = -1;
    color = false;
    hasMoved = false;
    nickName = 'Q';
}
Bishop::Bishop(int initialFile, int initialRank, bool pieceColor){
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