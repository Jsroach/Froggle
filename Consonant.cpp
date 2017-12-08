//
// Created by cn345 on 11/15/2017.
//
#include "Consonant.h"
#include "graphics.h"


Consonant::Consonant() {
    character = Consonant::generateConsonant();
    setHasLetter(true);
}

Consonant::Consonant(char characterIn){
    character = characterIn;
    setHasLetter(true);
}

Consonant::Consonant(int xIn, int yIn) : Consonant(){
    setX(xIn);
    setY(yIn);
    character = Consonant::generateConsonant();
}

Consonant::Consonant(char characterIn, int xIn, int yIn) : Piece(characterIn, xIn, yIn){
    setHasLetter(true);
}

void Consonant::movePiece() {
    //Changes direction of movement based on the Y coordinate
    if (getY() == UNIT1*11 && getX() > UNIT1) {
        setX(getX() - UNIT1); //Moves left
        if (getX() == UNIT1) {
            setX(UNIT1*11);
        }
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
    for (char cPiece : cPieces) {
        //If it is a consonant check
        if (characterIn == cPiece) {
            check = true;
            break;
        }
    }

    if (check) {
        character = characterIn;
        setHasLetter(true);
        drawLetter();
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

void Consonant::draw() {
    glColor3f(0, 0, 1);
    glBegin(GL_QUADS);
    // top left corner
    glVertex2i(getX(), getY());
    // top right corner
    glVertex2i(getX() + 50, getY());
    // bottom right corner
    glVertex2i(getX() + 50, getY() + 50);
    // bottom left corner
    glVertex2i(getX(), getY() + 50);
    glEnd();

    drawLetter();
}