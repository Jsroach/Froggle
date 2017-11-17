//
// Created by cn345 on 11/15/2017.
//
#include "Consonant.h"


Consonant::Consonant() = default;

Consonant::Consonant(char characterIn){
    character = characterIn;
}

Consonant::Consonant(char characterIn, int xIn, int yIn) : Piece(characterIn, xIn, yIn){}

void Consonant::movePiece() {
    if (getY() == SPACE && getX() > 0) {
        setX(getX() - SPACE);
    }else if (getY() == SPACE*2 && getX() < 500) {
        setX(getX() + SPACE);
    }else {
        cout << "Car is off the road!" << endl;
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

char Consonant::generateConsonant() {
    int n = rand() % 20;
    char letter = cPieces[n];
    return letter;
}