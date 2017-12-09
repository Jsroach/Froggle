//
// Created by cn345 on 11/15/2017.
//
#include <iostream>
#include "Piece.h"
#include "graphics.h"

Piece::Piece() = default;

Piece::Piece(char characterIn) {
    character = characterIn;
    hasLetter = true;
}

Piece::Piece (char characterIn, int xIn, int yIn) {
    character = characterIn;
    x = xIn;
    y = yIn;
    hasLetter = true;
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
    Piece::x = xIn;
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

// Checks to make sure the piece has a letter before drawing it on the screen.
void Piece::drawLetter() {
    if (getHasLetter()) {
        glColor3f(1, 1, 1);
        glRasterPos2i(getX() + 20, getY() + 30);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, getCharacter());
        glEnd();
    }
}

bool Piece::getHasLetter() {
    return hasLetter;
}

void Piece::setHasLetter(bool hasLetter) {
    Piece::hasLetter = hasLetter;
}


