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
    //Constructors
    Vowel();
    explicit Vowel(char c);
    Vowel(char c, int x, int y);
    Vowel(int x, int y);

    //setters
    void setCharacter(char characterIn) override;

    //moves piece by amount that the public field SPACE, checks position to make sure piece is able to be moved
    void movePiece() override;
    
    //randomly generates a vowel (including Y) for when a moving piece is created on board
    char generate_vowel();

protected:
    vector<char> letters = {'a','e','i','o','u','y'}; //list of possible values which are used when generating pieces
};


#endif //MCJJ_VOWEL_H
