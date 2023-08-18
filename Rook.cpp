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
   
    return false;
}
bool Rook::capture(int newRank, int newFile, Piece* board[][8]){
    if(isValidCapture(newRank, newFile,board)){
        rank = newRank;
        file = newFile;
        return true;
    }
    return false;
}
bool Rook::isValidCapture(int newRank, int newFile, Piece* board[][8]){
    return false;
}
//bool Rook::isValidMove2(int newRank, int newFile,  Piece* board[][8]){
  //  std::cout << " Rook validmove 2" << std::endl;
    //return false;
//}