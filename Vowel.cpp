//
// Created by Jack Roach on 11/15/17.
//

#include "Vowel.h"

Vowel::Vowel() {
    character = Vowel::generate_vowel();
}

Vowel::Vowel(char c) : Vowel() {
    character = c;
}

Vowel::Vowel(char c, int x, int y) : Vowel() {
    character = c;
    setX(x);
    setY(y);
}

Vowel::Vowel(int x, int y) : Vowel() {
    Piece::setX(x);
    Piece::setY(y);
}

void Vowel::movePiece() {
    if (getY() == SPACE && getX() > 0) {
        setX(getX() - SPACE);
    }else if (getY() == SPACE*2 && getX() < 500) {
        setX(getX() + SPACE);
    }else {
        cout << "Car is off the road!" << endl;
    }
}

void Vowel::setCharacter(char characterIn) {
    bool check = false;
    for (int i = 0; i < letters.size(); i++) {
        if (characterIn == letters[i]) {
            check = true;
            break;
        }else;
    }
    if (check == true) {
        character = characterIn;
    }else {
        cout << "Character is not a Vowel" << endl;
    }
}

char Vowel::generate_vowel() {
    int n = rand() % 6;
    char letter = letters[n];
    return letter;
}
