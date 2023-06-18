#include "Queen.h"
Queen::Queen(){
    file = -1;
    rank = -1;
    color = false;
    hasMoved = false;
    nickName = 'Q';
}
Queen::Queen(int initialRank, int initialFile, bool pieceColor){
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

bool Queen::isValidMove(int newRank, int newFile){
    return false;
}
bool Queen::capture(int newRank, int newFile){
    return false;
}