#include "Pawn.h"
#include "Chessboard.h"
#include <iostream>
Pawn::Pawn(){
    file = -1;
    rank = -1;
    color = false; //black
    hasMoved = false;
    nickName = 'P';
}
Pawn::Pawn(int initialRank, int initialFile, bool pieceColor){
    file = initialFile;
    rank = initialRank;
    color = pieceColor;
    hasMoved = false;
    nickName='P';
}

bool Pawn::move(int newRank, int newFile, Piece* board[][8]){
    //TODO: add checking to see if rook can move there.
    if(isValidMove(newRank,newFile,board)){
        rank = newRank;
        file = newFile;
        return true;
    }
    return false;
}

bool Pawn::isValidMove(int newRank, int newFile, Piece* board[][8]){
    
    if(newFile != file){ //seperate method for capturing. 
        return false; //can only move in straight lines
       
    }
    if(isWhite()){
      //  std::cout<<"white" << std::endl;
        if(newRank >= rank){ //white pieces can only move forwards
            //white starts on "rank/index 7" so moving up is down in rank number
            return false; 
        }
        else if( (rank == 6) && (newRank == 4) ){
            //pawn moving up 2 places on first move
            //captures will be done in different method
            return true;
        }
        else if ( newRank == rank - 1){
         //   std::cout<<"moving one spot" << std::endl;
            return true;
        }
        else{
            return false;
        }

    }
    else{
        if(newRank <= rank){ //pawns only move forwards
            //black starts on "rank/index 0" so moving up is down in rank number
            return false; 
        }
        else if( (rank == 1) && (newRank == 3) ){
            //pawn moving up 2 places on first move
            //captures will be done in different method
            return true;
        }
        else if ( newRank == rank + 1){
            return true;
        }
    }
return false;
}
bool Pawn::isWhite(){
    return color;
}
bool Pawn::isValidCapture(int newRank, int newFile, Piece* board[][8]){
    if (newFile == file){ //pawns can only capture on the diagnal
        return false;
    }
    if(isWhite()){
        if(newRank >= rank){ //white pieces can only move up the board
            return false; 
        }
    }
    else{ //black
        if(newRank <= rank){ //black pieces can only move down the board
            return false;
        }
    }
    if( !( (file + 1 == newFile)||(file - 1 == newFile) ) ){ //can only capture one file over
        return false;
    }
return true;
}
bool Pawn::capture(int newRank, int newFile, Piece* board[][8]){
   if(isValidCapture(newRank, newFile,board)){
        rank = newRank;
        file = newFile;
        return true;
   }
    return false;
}