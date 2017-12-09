//
// Created by Jack Roach on 11/15/17.
//

#include "Vowel.h"
#include "graphics.h"


Vowel::Vowel() {
    character = Vowel::generateVowel(); //chooses a vowel randomly to set as the character field for the created piece
    setHasLetter(true);
}

Vowel::Vowel(char c) : Vowel() {
    character = c;
    setHasLetter(true);
}

Vowel::Vowel(char c, int x, int y) : Piece(c, x, y) {
    setHasLetter(true);
}
Vowel::Vowel(int xIn, int yIn) : Vowel(){

}

Vowel::Vowel(const Vowel &v) {};

void Vowel::movePiece() {
    setX(getX() - UNIT1); //Moves left
    if (getX() < 0) {
        setX(UNIT1*11);
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
    glColor3f(.7, 0, 1);
    glBegin(GL_QUADS);
    // top left corner
    glVertex2i(getX()+5, getY()+5);
    // top right corner
    glVertex2i(getX() + 45, getY()+5);
    // bottom right corner
    glVertex2i(getX() + 45, getY() + 45);
    // bottom left corner
    glVertex2i(getX()+5, getY() + 45);
    glEnd();

    drawLetter();
}
