/* 
Author: Erik B.
Let's make some anarchy chess
*/

#include <iostream>
#include <vector>
#include "Chessboard.h"

bool checkMate = false;

int main(){
//set up the board 
//while !checkMate get next move

//while(!checkMate){
Chessboard myChessBoard;
myChessBoard.displayBoard();
while(!checkMate){

    /*std::cout << " enter a position and i will return the rank and file "<< std::endl;
    std::string input;
    std::getline(std::cin, input);
    myChessBoard.returnRankFile(input);
  */
    std::cout << " What piece would you like to move? \n Enter the rank and file and final rank and file ex. \"e2e4\" "<< std::endl;
    std::string input;
    std::getline(std::cin, input);
    if( myChessBoard.isValidInput(input) ){
      myChessBoard.displayBoard();
    }
    else{ std::cout << " Game: That wasn't a valid move. Please try again" << std::endl; }
  
//}
}
return 0;
}
