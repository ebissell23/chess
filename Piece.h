//Piece.h
//Erik B.
#ifndef PIECE_H
#define PIECE_H
class Chessboard;
class Piece {
    protected:
        int file; 
        int rank;
        bool color;
        bool hasMoved;
        char nickName;
    public:
        //constructors
        Piece();
        Piece(int initialFile, int initialRank, bool pieceColor);
        Piece(const Piece& other);
        //member functions
        virtual bool move(int newRank, int newFile, Piece* board[][8]) = 0;
        char getNickname();
        void setNickname(char newNickname);
        virtual bool isValidMove(int newRank, int newFile, Piece* board [][8]) = 0;
        virtual ~Piece();
        virtual bool isValidCapture(int newRank, int newFile, Piece* board[][8]) = 0;
        virtual bool capture(int newRank, int newFile, Piece* board[][8]) = 0;
       // virtual bool isValidMove2(int newRank, int newFile, Piece* board[][8]) = 0;
        

};

#endif