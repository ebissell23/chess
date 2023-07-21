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

bool Pawn::move(int newRank, int newFile, Chessboard& chessboard){
    //TODO: add checking to see if rook can move there.
    rank = newRank;
    file = newFile;
    return true;
}

bool Pawn::isValidMove(int newRank, int newFile){
    std::cout<<"\n start of Pawn isValidMove()" << std::endl;
    std::cout <<"Rank: " << rank << std::endl;
    std::cout <<"File: " << file << std::endl;
    std::cout <<"NewRank: " << newRank << std::endl;
    std::cout <<"newFile: " << newFile << std::endl;
    if(newFile != file){ //seperate method for capturing. 
         std::cout<<"Pawns can only change files if they capture" << std::endl;
        return false; //can only move in straight lines
       
    }
    if(isWhite()){
        std::cout<<"white" << std::endl;
        if(newRank >= rank){ //white pieces can only move forwards
            //white starts on "rank/index 7" so moving up is down in rank number
            std::cout<<"moving wrong way" << std::endl;
            return false; 
        }
        else if( (rank == 6) && (newRank == 4) ){
            //pawn moving up 2 places on first move
            //captures will be done in different method
            std::cout<<"moving 2 spots" << std::endl;
            rank = newRank;
            return true;
        }
        else if ( newRank == rank - 1){
            std::cout<<"moving one spot" << std::endl;
            rank = newRank;
            return true;
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
            rank = newRank;
            return true;
        }
        else if ( newRank == rank + 1){
            rank = newRank;
            return true;
        }
    }
std::cout<<"end of method somehow" << std::endl;
return false;
}
bool Pawn::isWhite(){
    return color;
}
bool Pawn::isValidCapture(int newRank, int newFile){
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
    if( !( (file + 1 == newFile)||(file - 1) ) ){ //can only capture one file over
        return false;
    }
    

}
bool Pawn::capture(int newRank, int newFile){
    return false;
}