#include "Queen.h"
Queen::Queen(){
    file = -1;
    rank = -1;
    color = false;
    hasMoved = false;
    nickName = 'Q';
}
Queen::Queen(int initialFile, int initialRank, bool pieceColor){
    file = initialFile;
    rank = initialRank;
    color = pieceColor;
    hasMoved = false;
    nickName='Q';
}

bool Queen::move(int newRank, int newFile){
    //TODO: add checking to see if Queen can move there.
    rank = newRank;
    file = newFile;
    return true;
}