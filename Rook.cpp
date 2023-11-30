#include "Rook.h"
#include <iostream>
Rook::Rook(){
    file = -1;
    rank = -1;
    color = false;
    hasMoved = false;
    nickName = 'R';
}
Rook::Rook(int initialRank, int initialFile, bool pieceColor){
    file = initialFile;
    rank = initialRank;
    color = pieceColor;
    hasMoved = false;
    nickName='R';
}

bool Rook::move(int newRank, int newFile, Piece* board[][8]){
   if(isValidMove(newRank, newFile,board)){
        rank = newRank;
        file = newFile;
        return true;
    }
    return false;
}
bool Rook::isValidMove(int newRank, int newFile, Piece* board[][8]){
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
bool Rook::capture(int newRank, int newFile, Piece* board[][8]){
    std::cout << "Rook: capture() " << std::endl;
    if(isValidCapture(newRank, newFile,board)){
        rank = newRank;
        file = newFile;
        return true;
    }
    return false;
}
bool Rook::isValidCapture(int newRank, int newFile, Piece* board[][8]){
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
//bool isWhite(){
  //  return color;
//}
//bool Rook::isValidMove2(int newRank, int newFile,  Piece* board[][8]){
  //  std::cout << " Rook validmove 2" << std::endl;
    //return false;
//}