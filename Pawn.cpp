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
    std::cout<< "pawn.move" <<std::endl;
    if(isValidMove(newRank,newFile,board)){
        rank = newRank;
        file = newFile;
        return true;
    }
    return false;
}

bool Pawn::isValidMove(int newRank, int newFile, Piece* board[][8]){
    
    if(newFile != file){ //seperate method for capturing. 
         std::cout<<"Pawns can only change files if they capture" << std::endl;
        return false; //can only move in straight lines
       
    }
    if(isWhite()){
      //  std::cout<<"white" << std::endl;
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
         //   std::cout<<"moving one spot" << std::endl;
            return true;
        }
        else{
            std::cout << "trying to move too many positions" << std::endl;
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
std::cout<<"end of method somehow" << std::endl;
return false;
}
bool Pawn::isWhite(){
    return color;
}
bool Pawn::isValidCapture(int newRank, int newFile, Piece* board[][8]){
 //   std::cout << "begin of isValid Capture" << std::endl;
    if (newFile == file){ //pawns can only capture on the diagnal
        std::cout << "Same File" << std::endl;
        return false;
    }
    if(isWhite()){
        if(newRank >= rank){ //white pieces can only move up the board
            return false; 
        }
    }
    else{ //black
        if(newRank <= rank){ //black pieces can only move down the board
        std::cout << "black" << std::endl;
            return false;
        }
    }
    if( !( (file + 1 == newFile)||(file - 1 == newFile) ) ){ //can only capture one file over
    std::cout << "Trying to move many files" << std::endl;
        return false;
    }
    std::cout << "end" << std::endl;
return true;
}
bool Pawn::capture(int newRank, int newFile, Piece* board[][8]){
    std::cout << "pawn capture" << std::endl;
   if(isValidCapture(newRank, newFile,board)){
       // std::cout << "is valid capture" << std::endl;
        rank = newRank;
        file = newFile;
        return true;
   }
    return false;
}

/*  std::cout<<"\n start of Pawn isValidMove()" << std::endl;
    std::cout <<"Rank: " << rank << std::endl;
    std::cout <<"File: " << file << std::endl;
    std::cout <<"NewRank: " << newRank << std::endl;
    std::cout <<"newFile: " << newFile << std::endl;
    */