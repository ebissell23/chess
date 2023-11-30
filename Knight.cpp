#include <iostream>
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

bool Knight::move(int newRank, int newFile, Piece* board[][8]){
    //TODO: add checking to see if Knight can move there.
    if(isValidMove(newRank, newFile, board)){
        rank = newRank;
        file = newFile;
        return true;
    }
    return false;
}
bool Knight::isValidMove(int newRank, int newFile, Piece* board[][8]){
    std::cout << "knight: isValidMove" << std::endl;
    int dRank[] = {1,1,-1,-1,2,2,-2,-2}; // relative moves from current position
    int dFile[] = {2,-2,2,-2,1,-1,1,-1}; //
    std::cout << "trying to get to: " << newRank << newFile << std::endl;
    for (int i = 0; i < 8; i++){ //iterate through all relative moves and check if attempted move works
        int potentialRank = rank + dRank[i];
        int potentialFile = file + dFile[i];
        std::cout << "/n potentialRank : " << potentialRank << std::endl;
        std::cout << " potentialFile : " << potentialFile << std::endl;
        if( (potentialRank == newRank) && (potentialFile == newFile) ){
            return true;
        }
    }
    return false;
}
bool Knight::capture(int newRank, int newFile, Piece* board[][8]){
    if(isValidCapture(newRank,newFile, board)){
        rank = newRank;
        file = newFile;
        return true;
    }
    return false;
}
bool Knight::isValidCapture(int newRank, int newFile, Piece* board[][8]){
    return true;
}