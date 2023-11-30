#include <iostream>
#include "Bishop.h"
Bishop::Bishop(){
    file = -1;
    rank = -1;
    color = false;
    hasMoved = false;
    nickName = 'B';
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
    std::cout << "Bishop: Move" << std::endl;
    if(isValidMove(newRank,newFile, board)){
    rank = newRank;
    file = newFile;
    return true;
    }
    return false;
    
}

bool Bishop::isValidMove(int newRank, int newFile, Piece* board[][8]){
    int rankDifference = std::abs(newRank - rank);
    int fileDifference = std::abs(newFile - file);

    std::cout<< "rankDiff: " << rankDifference << "FileDiff: " << fileDifference << std::endl;
    if(rankDifference != fileDifference){
        std::cout << "must move diagnally"<<std::endl;
        return false;
    }
    //rank > new rank -1
    int rankDirection = 0;
    int fileDirection = 0;
    if(rank > newRank){
        rankDirection = -1;
        }
    else{
        rankDirection = 1;
    }
    if ( file > newFile){
         fileDirection = -1;
    }
    else{
        fileDirection = 1;
    }

    for (int i = 1; i < rankDifference; i++){
        int intermediateRank = rank + (i * rankDirection);
        int intermediateFile = file + (i * fileDirection);
        std::cout<< "IntermediateRank: " << intermediateRank << std::endl;
        std::cout<< "IntermediateFile: " << intermediateFile << std::endl;
       // std::cout<< "IntermediateSquare: " << board[intermediateRank][intermediateFile]->getNickname() << std::endl;
        if ( !(board[intermediateRank][intermediateFile] == nullptr) ){
            std::cout<<" Bishop: intermediate square has piece" << std::endl;
            return false;
        }
    }
    return true;
}
bool Bishop::capture(int newRank, int newFile, Piece* board[][8]){
    if (isValidCapture(newRank,newFile,board)){
        rank = newRank;
        file = newFile;
        return true;
    }
    return false;
}
bool Bishop::isValidCapture(int newRank, int newFile, Piece* board[][8]){
    std::cout << "bishop isValidcapture" <<std::endl;
    if(color == board[newRank][newFile]->isWhite()){
        std::cout << "Bishop: Can't Capture Own Piece \n" << std::endl;
        return false; 
    }

    int rankDifference = std::abs(newRank-rank);
    int fileDifference = std::abs(newFile - file);
    if(rankDifference != fileDifference){
        std::cout << "must move diagnally"<<std::endl;
        return false;
    }
    //rank > new rank -1
    int rankDirection = 0;
    int fileDirection = 0;
    if(rank > newRank){
        rankDirection = -1;
        }
    else{
        rankDirection = 1;
    }
    if ( file > newFile){
         fileDirection = -1;
    }
    else{
        fileDirection = 1;
    }
    if(  (rankDifference == 1) && (fileDifference == 1) ){ // right next to it
        return true;
    }
    
    for (int i = 1; i < rankDifference - 1; i++){
        int intermediateRank = rank + (i * rankDirection);
        int intermediateFile = file + (i * fileDirection);
       // std::cout<< "IntermediateRank: " << intermediateRank << std::endl;
       // std::cout<< "IntermediateFile: " << intermediateFile << std::endl;
        //std::cout<< "IntermediateSquare: " << board[intermediateRank][intermediateFile] << std::endl;
        if ( !(board[intermediateRank][intermediateFile] == nullptr) ){
            std::cout<<" Bishop: intermediate square has a : " <<board[intermediateRank][intermediateFile]->getNickname() << std::endl;
            return false;
        }
    }
    return true;
}