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
    //Changes direction of movement based on the Y coordinate
    if (getY() == SPACE && getX() > 0) {
        setX(getX() - SPACE); //Moves left
    }else if (getY() == SPACE*2 && getX() < 500) {
        setX(getX() + SPACE);//Moves right
    }else {
        //Y coordinate is incorrect, the car is off the road
        cout << "Car is off the road!" << endl;
    }
}

void Consonant::setCharacter(char characterIn) {
    bool check = false;
    //Makes sure the character is a consonant
    for (int i = 0; i < cPieces.size(); i++) {
        //If it is a consonant check
        if (characterIn == cPieces[i]) {
            check = true;
            break;
        }else; //If it isnt dont do anything to check
    }
    if (check == true) {
        character = characterIn;
    }else {
        cout << "Character is not a consonant" << endl;
    }
}

char Consonant::generateConsonant() {
    //Determine random letter
    int n = rand() % 20;
    char letter = cPieces[n];
    return letter;
}