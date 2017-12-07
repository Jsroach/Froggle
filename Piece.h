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
    bool hasLetter;

protected:
    char character;

public:
    int SPACE = 10; //establishes unit conversion for piece length to graphics units
    
    //constructors
    Piece();
    explicit Piece(char characterIn);
    Piece(char characterIn, int xIn, int yIn);
    
    //getters
    int getPosition() const;
    int getX() const;
    int getY() const;
    char getCharacter() const;

    //setters
    void setPosition(int x, int y);
    void setX(int xIn);
    void setY(int yIn);

    // draw letter
    void drawLetter(int x, int y, char character);

    //virtual method to move piece
    virtual void movePiece() = 0;
    //virtual method to set the character for the class
    virtual void setCharacter(char characterIn) = 0;
};


#endif //MCJJ_PIECE_H
