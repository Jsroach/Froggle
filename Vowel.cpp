//
// Created by Jack Roach on 11/15/17.
//

#include "Vowel.h"
#include "Piece.h"

Vowel::Vowel() : Piece() {
}

Vowel::Vowel(char c) : Piece(c) {
    Piece::setCharacter(c);
}

Vowel::Vowel(char c, int x, int y) : Piece(c,x,y) {
}

Vowel::Vowel(int x, int y) : Piece() {
    Piece::setX(x);
    Piece::setY(y);
}

char Vowel::generate_vowel() {
    return 0;
}
