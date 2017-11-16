//
// Created by Jack Roach on 11/15/17.
//

#include "Vowel.h"
#include <random>

Vowel::Vowel() : Piece() {
    Vowel::generate_vowel();
}

Vowel::Vowel(char c) : Vowel(), Piece(c) {
    Piece::setCharacter(c);
}

Vowel::Vowel(char c, int x, int y) : Vowel(), Piece(c,x,y) {
}

Vowel::Vowel(int x, int y) : Vowel() {
    Piece::setX(x);
    Piece::setY(y);
}

char Vowel::generate_vowel() {
    int n = rand() % 6;
    char letter = letters[n];
    return letter;
}
