//
// Created by cn345 on 11/15/2017.
//
#include <iostream>
#include "Piece.h"

Piece::Piece() = default;

Piece::Piece(char characterIn) {
    character = characterIn;
}

Piece::Piece (char characterIn, int xIn, int yIn) {
    character = characterIn;
    x = xIn;
    y = yIn;
}
void Piece::setPosition(int x, int y) {
    Piece::x = x;
    Piece::y = y;
}

int Piece::getPosition() const {
    cout << "Position: (" << x << ", " << y << ")" << endl; //displays current position of piece
    return x,y; //returns 2 variables, x and y
}
void Piece::setX(int xIn) {
    x = xIn;
}

void Piece::setY(int yIn) {
    y = yIn;
}
int Piece::getX() const {
    return x;
}
int Piece::getY() const {
    return y;
}

char Piece::getCharacter() const {
    return character;
}

void Piece::movePiece() {
    cout << "Moving piece" << endl;
}

void Piece::setCharacter(char characterIn) {
    cout << "Setting character" << endl;
}


