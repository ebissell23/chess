#include "Knight.h"
Knight::Knight(){
    file = -1;
    rank = -1;
    color = false;
    hasMoved = false;
    nickName = 'N';
}
Knight::Knight(int initialRank, int initialFile, bool pieceColor){
    file = initialFile;
    rank = initialRank;
    color = pieceColor;
    hasMoved = false;
    nickName='N';
}

bool Knight::move(int newRank, int newFile){
    //TODO: add checking to see if Knight can move there.
    rank = newRank;
    file = newFile;
    return true;
}
bool Knight::isValidMove(int newRank, int newFile){
    return false;
}
bool Knight::capture(int newRank, int newFile){
    return false;
}