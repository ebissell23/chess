#include <iostream>
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

bool Queen::move(int newRank, int newFile, Piece* board[][8]){
    //TODO: add checking to see if Queen can move there.
    if(isValidMove(newRank, newFile, board)){
        rank = newRank;
        file = newFile;
        return true;
    }
    return false;
}

bool Queen::isValidMove(int newRank, int newFile, Piece* board[][8]){

    if(isValidBishopMove(newRank, newFile, board) || isValidRookMove(newRank, newFile, board)){
        return true;
    }
    return false;
}
bool Queen::capture(int newRank, int newFile, Piece* board[][8]){
    if(isValidCapture(newRank, newFile, board)){
        rank = newRank;
        file = newFile;
        return true;
    }
    return false;
}
bool Queen::isValidCapture(int newRank, int newFile, Piece* board[][8]){
    if(isValidBishopCapture(newRank, newFile, board)|| isValidRookCapture(newRank, newFile, board)){
        return true;
    }
    return false;
}

bool Queen::isValidBishopMove(int newRank, int newFile, Piece* board[][8]){
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
bool Queen::isValidBishopCapture(int newRank, int newFile, Piece* board[][8]){
   
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
bool Queen::isValidRookMove(int newRank, int newFile, Piece* board[][8]){
    std::cout <<"rook isValid Move" << std::endl;
    //check if the move is vertical
    std::cout << "Rank: " << rank <<std::endl;
    std::cout << "newRank: " << newRank << std::endl;
    std::cout << "File: " << file <<std::endl;
    std::cout << "newFile: " << newFile << std::endl;
    int step = -1;
    if((file == newFile) && (rank != newRank)){
        if(rank > newRank){
            step = -1;
            std::cout << "step is -1" << std::endl;
        } 
        else{
            std::cout << "step is  1" << std::endl;
            step = 1;
        }
        
        for(int i = rank + step; i !=newRank; i += step ){
            std::cout << "i: "<< i << std::endl;
            std::cout << "file: " << newFile << std::endl;
            if(board[i][newFile] != nullptr){
                std::cout << "vertical: not null ptr at : " << i << std::endl;
                return false;
            }
            return true;
        }
    } 
    //check if the move is horizontal
    else if( (rank == newRank) && (file != newFile)){
        if(file > newFile){
            step = -1;
        }
        else{
            step = 1;
        }
        for(int i = file + step; i != newFile; i += step){
            if(board[newRank][i]!=nullptr){
                return false;
            }
        }
        return true;
    }
    std::cout << "end of rook.isValidMove Func()"<<std::endl; 
    return false;
  

}
bool Queen::isValidRookCapture(int newRank, int newFile, Piece* board[][8]){
    std::cout << "rook: isValidCapture()" << std::endl;
    if (board[newRank][newFile] == nullptr){ // can't capture on nothing
        std::cout << "rook: Can't capture empty square" << std::endl;
        return false;
    }
    else if(color == board[newRank][newFile]->isWhite()){
        std::cout << "rook: Can't capture same color piece" << std::endl;
        return false;
    }
    int rankDifference = newRank - rank;
    int fileDifference = newFile - file;
    std::cout << "rankDifference: " << rankDifference << std::endl;
    std::cout << "fileDifference: " << fileDifference << std::endl;
    if ( ((rankDifference != 0) && (fileDifference != 0) ) ){ //one of them needs to be 0
        std::cout << "rank/File diff error" << std::endl;
        return false;
    }
    if( (std::abs(rankDifference) == 1) ^ (std::abs(fileDifference) == 1) ){ // only moving one position
        std::cout << "only capturing one away" << std::endl;
        return true;
    }
    //call isValidMove to see if we can move to one position before the capturing position.
    if (newRank > rank){
        std::cout << "newRank > rank" << std::endl;
        return isValidMove(newRank + 1, newFile, board);
    }else{
        std::cout << "newRank > rank" << std::endl;
        return isValidMove(newRank - 1, newFile, board);
    }

    return false;
}