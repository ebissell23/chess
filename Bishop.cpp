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

bool Bishop::move(int newRank, int newFile, Piece* board[][8]){
    //TODO: add checking to see if Bishop can move there.
    rank = newRank;
    file = newFile;
    return true;
}
bool Bishop::isValidMove(int newRank, int newFile, Piece* board[][8]){
    return false;
}
bool Bishop::capture(int newRank, int newFile, Piece* board[][8]){
    return false;
}
bool Bishop::isValidCapture(int newRank, int newFile, Piece* board[][8]){
    return false;
}