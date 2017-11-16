//
// Created by cn345 on 11/15/2017.
//
#include "Piece.h"

Piece::Piece() = default;

//Piece::Piece(char character) : Piece::setCharacter(character) {}

Piece::Piece(char characterIn) {
    character - characterIn;
}

Piece::Piece (char characterIn, int xIn, int yIn) {
    character = characterIn;
    x = xIn;
    y = yIn;
}
void position() {
    cout << "Position: (" << x << ", " << y << ")" << endl;
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
void Piece::setCharacter(char characterIn) {
    character = characterIn;
}
char Piece::getCharacter() const {
    return character;
}