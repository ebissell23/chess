//Piece.h
//Erik B.
#ifndef PIECE_H
#define PIECE_H

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
        bool move(int newRank, int newFile);
        char getNickname();
        void setNickname(char newNickname);
        virtual bool isValidMove(int newRank, int newFile) = 0;
        virtual ~Piece();
        virtual bool isValidCapture(int newRank, int newFile) = 0;
        virtual bool capture(int newRank, int newFile) = 0;
        

};

#endif