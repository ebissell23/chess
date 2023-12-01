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
    //check if the move is vertical
    int step = -1;
    if((file == newFile) && (rank != newRank)){
        if(rank > newRank){
            step = -1;
        } 
        else{
            step = 1;
        }
        
        for(int i = rank + step; i !=newRank; i += step ){
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
    if (board[newRank][newFile] == nullptr){ // can't capture on nothing
        return false;
    }
    else if(color == board[newRank][newFile]->isWhite()){
        return false;
    }
    int rankDifference = newRank - rank;
    int fileDifference = newFile - file;
    if ( ((rankDifference != 0) && (fileDifference != 0) ) ){ //one of them needs to be 0
        return false;
    }
    if( (std::abs(rankDifference) == 1) ^ (std::abs(fileDifference) == 1) ){ // only moving one position
        return true;
    }
    //call isValidMove to see if we can move to one position before the capturing position.
    if (newRank > rank){
        return isValidMove(newRank + 1, newFile, board);
    }else{
        return isValidMove(newRank - 1, newFile, board);
    }

    return false;
}
