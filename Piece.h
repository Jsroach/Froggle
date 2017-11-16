//
// Created by Jacob Jonsson on 2017-11-14.
//

#ifndef MCJJ_PIECE_H
#define MCJJ_PIECE_H

#include <vector>
using namespace std;

class Piece {
private:
    char character;
    int x;
    int y;

public:
    Piece();

    Piece(char characterIn);

    Piece(char characterIn, int xIn, int yIn);

    virtual void setPosition(int x, int y) = 0;
    virtual void movePiece() = 0;
    void position();
    void setX(int xIn);
    void setY(int yIn);
    int getX() const;
    int getY() const;
    void setCharacter(char characterIn);
    char getCharacter() const;
};


#endif //MCJJ_PIECE_H
