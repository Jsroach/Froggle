//
// Created by Jacob Jonsson on 2017-11-14.
//

#ifndef MCJJ_PIECE_H
#define MCJJ_PIECE_H

#include <iostream>
#include <vector>
using namespace std;


class Piece {
private:
    int x;
    int y;
protected:
    char character;
public:
    int SPACE = 10;
    Piece();

    explicit Piece(char characterIn);

    Piece(char characterIn, int xIn, int yIn);

    virtual void movePiece() = 0;
    virtual void setCharacter(char characterIn) = 0;
    void setPosition(int x, int y);
    void getPosition();
    void setX(int xIn);
    void setY(int yIn);
    int getX() const;
    int getY() const;
    char getCharacter() const;
};


#endif //MCJJ_PIECE_H
