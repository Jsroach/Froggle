//
// Created by Jacob Jonsson on 2017-11-14.
//

#ifndef MCJJ_PIECE_H
#define MCJJ_PIECE_H

class Piece {
private:
    char character;
    int x;
    int y;

public:
    Piece() {}

    Piece(char character) : character(character) {}

    virtual bool checkPosition() = 0;
    virtual void setPosition(int x, int y) = 0;
    virtual void setCharacter(char character) = 0;
    virtual char getCharacter() = 0;
    virtual void movePiece() = 0;
};

#endif //MCJJ_PIECE_H
