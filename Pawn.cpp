#include "Pawn.h"
Pawn::Pawn(){
    file = -1;
    rank = -1;
    color = false;
    hasMoved = false;
    nickName = 'P';
}
Pawn::Pawn(int initialFile, int initialRank, bool pieceColor){
    file = initialFile;
    rank = initialRank;
    color = pieceColor;
    hasMoved = false;
    nickName='P';
}

bool Pawn::move(int newRank, int newFile){
    //TODO: add checking to see if rook can move there.
    rank = newRank;
    file = newFile;
    return true;
}