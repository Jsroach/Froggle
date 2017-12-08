//
// Created by Jack Roach on 11/15/17.
//

#include "Vowel.h"
#include "graphics.h"


Vowel::Vowel() {
    character = Vowel::generateVowel();
}

Vowel::Vowel(char characterIn){
    character = characterIn;
}

Vowel::Vowel(int xIn, int yIn) : Vowel(){

}

Vowel::Vowel(char characterIn, int xIn, int yIn) : Piece(characterIn, xIn, yIn){}

Vowel::Vowel(const Vowel &v) {};

void Vowel::movePiece() {
    if (getY() == SPACE && getX() > 0) { //moves piece to the left if it is in a certain row (lane)
        setX(getX() - 50);
    }else if (getY() == SPACE*2 && getX() < 500) { //moves piece to the right if it is in a specific row (lane)
        setX(getX() + SPACE);
    }else {
        cout << "Car is off the road!" << endl; //error message
    }
}

void Vowel::setCharacter(char characterIn) {
    bool check = false;
    for (char letter : letters) { //checks to make sure inputted character is in vowels vector (is a vowel)
        if (characterIn == letter) {
            check = true;
            break;
        }
    }

    if (check) {
        character = characterIn; //sets character if input is a vowel
        setHasLetter(true);
        drawLetter();
    }else {
        cout << "Character is not a Vowel" << endl; //displays error message if input is not a vowel
    }
}

char Vowel::generateVowel() { //randomly returns a vowel out of the 6 existing vowels (Y included)
    int n = rand() % 6;
    char letter = letters[n];
    return letter;
}

void Vowel::draw() {
    glColor3f(1, 0, 0);
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
