#include "Chessboard.h"
#include "Piece.h"
#include <iostream>

Chessboard::Chessboard() {
    for(int i = 0; i < BOARD_SIZE; i++){
        for (int j = 0; j < BOARD_SIZE; j++){
                board[i][j] = Piece();
        }
    }

    // set up board with pieces
    // [rank][file]
    //black major pieces
    Rook ra8(0,0,false);
    board[0][0] = ra8;
    Knight nb8(0,1,false);
    board[0][1] = nb8;
    Bishop bc8(0,3,false);
    board[0][2] = bc8;
    Queen qd8(0,4,false);
    board[0][3] = qd8;
    King ke8(0,5,false);
    board[0][4] = ke8;
    Bishop bf8(0,6,false);
    board[0][5] = bf8;
    Knight ng8(0,6,false);
    board[0][6] = ng8;
    Rook rh8(0,7,false);
    board[0][7] = rh8;
    //black pawns
    Pawn pa7(1,0,false);
    board[1][0] = pa7;
    Pawn pb7(1,1,false);
    board[1][1] = pb7;
    Pawn pc7(1,2,false);
    board[1][2] = pc7;
    Pawn pd7(1,3,false);
    board[1][3] = pd7;
    Pawn pe7(1,4,false);
    board[1][4] = pe7;
    Pawn pf7(1,5,false);
    board[1][5] = pf7;
    Pawn pg7(1,6,false);
    board[1][6] = pg7;
    Pawn ph7(1,7,false);
    board[1][7] = ph7;
    //white major pieces
    Rook ra1(7,0,true);
    board[7][0] = ra1;
    Knight nb1(7,1,true);
    board[7][1] = nb1;
    Bishop bc1(7,3,true);
    board[7][2] = bc1;
    Queen qd1(7,4,true);
    board[7][3] = qd1;
    King ke1(7,5,true);
    board[7][4] = ke1;
    Bishop bf1(7,6,true);
    board[7][5] = bf1;
    Knight ng1(7,6,true);
    board[7][6] = ng1;
    Rook rh1(7,7,true);
    board[7][7] = rh1;
    //white pawns
    Pawn pa2(6,0,true);
    board[6][0] = pa2;
    Pawn pb2(6,1,true);
    board[6][1] = pb2;
    Pawn pc2(6,2,true);
    board[6][2] = pc2;
    Pawn pd2(6,3,true);
    board[6][3] = pd2;
    Pawn pe2(6,4,true);
    board[6][4] = pe2;
    Pawn pf2(6,5,true);
    board[6][5] = pf2;
    Pawn pg2(6,6,true);
    board[6][6] = pg2;
    Pawn ph2(6,7,true);
    board[6][7] = ph2;
}
void Chessboard::displayBoard(){
    for (int i = 0; i < BOARD_SIZE; i++){
        for (int j = 0; j < BOARD_SIZE; j++){
            std::cout << board[i][j].getNickname() << " ";
        }
        std::cout << std::endl;
    }

}

    
