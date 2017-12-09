//
// Created by Jack Roach on 11/15/17.
//
#include "Piece.h"

#ifndef MCJJ_VOWEL_H
#define MCJJ_VOWEL_H

#include <vector>
using namespace std;

class Vowel : public Piece {
private:
    int UNIT1 = 50; //width/height of one unit on the playing field
public:
    //Constructors
    Vowel();
    explicit Vowel(char c);
    Vowel(char c, int x, int y);
    Vowel(int x, int y);
    Vowel(const Vowel &v);

    // setters
    void setCharacter(char characterIn) override;

    /**
     * Requires: nothing
     * Modifies: x coordinate
     * Effects:moves piece by amount that the public field SPACE, checks position to make sure piece is able to be moved
     */
    void movePiece() override;
    
    /**
     * Requires: Nothing
     * Modifies:Nothing
     * Effects: randomly generates a vowel (including Y) for when a moving piece is created on board
     */
    char generateVowel();
    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: draws the car on the playing field
     */
    void draw();

protected:
    vector<char> letters = {'a','e','i','o','u','y'}; //list of possible values which are used when generating pieces
};


#endif //MCJJ_VOWEL_H
