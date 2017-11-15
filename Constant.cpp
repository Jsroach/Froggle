//
// Created by cn345 on 11/15/2017.
//
#include "Constant.h"

Constant::Constant() = default {}

Constant::Constant(char characterIn) : setCharacter(characterIn) {}

void Constant::setPosition(int x, int y) {
    setX(x);
    setY(y);
}

void Constant::movePiece() {
    
}