#include "King.h"
King::King(){
    file = -1;
    rank = -1;
    color = false;
    hasMoved = false;
    nickName = 'K';
}
King::King(int initialRank, int initialFile, bool pieceColor){
    file = initialFile;
    rank = initialRank;
    color = pieceColor;
    hasMoved = false;
    nickName = 'K';
    
}

bool King::move(int newRank, int newFile){
    //TODO: add checking to see if King can move there.
    rank = newRank;
    file = newFile;
    return true;
}
bool King::isValidMove(int newRank, int newFile){
    return false;
}
bool King::capture(int newRank, int newFile){
    return false;
}
bool King::isValidCapture(int newRank, int newFile){
    return false;
}
