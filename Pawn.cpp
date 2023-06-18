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
         std::cout<<"wrong file" << std::endl;
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
            return true;
        }
        else if ( newRank == rank - 1){
            std::cout<<"moving one spot" << std::endl;
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
            return true;
        }
        else if ( newRank == rank + 1){
            return true;
        }
    }
std::cout<<"end of method somehow" << std::endl;
return false;
}
bool Pawn::isWhite(){
    return color;
}