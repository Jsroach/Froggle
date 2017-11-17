//
// Created by Jack Roach on 11/15/17.
//
#include "Piece.h"
#ifndef MCJJ_VOWEL_H
#define MCJJ_VOWEL_H

#include <vector>
using namespace std;

class Vowel : public Piece {
public:
    Vowel();
    explicit Vowel(char c);
    Vowel(char c, int x, int y);
    Vowel(int x, int y);

    void setCharacter(char characterIn) override;

    char generate_vowel();

protected:
    vector<char> letters = {'a','e','i','o','u','y'};
};


#endif //MCJJ_VOWEL_H
