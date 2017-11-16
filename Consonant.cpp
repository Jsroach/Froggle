//
// Created by cn345 on 11/15/2017.
//
#include "Consonant.h"
#include <iostream>

Consonant::Consonant() = default {}

Consonant::Consonant(char characterIn) : setCharacter(characterIn) {}

Consonant::Consonant(char characterIn, int xIn, int yIn) : setCharacter(characterIn), setX(xIn), setY(yIn) {}

void Consonant::movePiece() {
    if (getY() == SPACE && getX() > 0) {
        setX(getX() - SPACE);
    }else if (getY() == SPACE * 2 && getX() < SPACE * 50) {
        setX(getX() + SPACE);
    }
}

void Consonant::setCharacter(char characterIn) {
    bool check = false;
    for (int i = 0; i < cPieces.size(); i++) {
        if (characterIn == cPieces[i]) {
            check = true;
            break;
        }else;
    }
    if (check == true) {
        character = characterIn;
    }else {
        cout << "Character is not a consonant" << endl;
    }
}