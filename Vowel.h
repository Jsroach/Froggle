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
    int UNIT1 = 50;
public:
    //Constructors
    /**
     * Requires: None
     * Modifies: None
     * Effects: Default Constructor
     */
    Vowel();

    /**
     * Requires: char that is a vowel
     * Modifies: Piece::character
     * Effects: Creates a vowel with only a character and no coordinates
     */
    explicit Vowel(char c);

    /**
    * Requires: x value, y value
    * Modifies: x,y
    * Effects: Creates a vowel with full coordinates
    */
    Vowel(int x, int y);

    /**
     * Requires: char that is a vowel, x value, y value
     * Modifies: Piece::character, x,y
     * Effects: Creates a vowel with a character and full coordinates
     */
    Vowel(char c, int x, int y);

    /**
     * Creates a vowel object by referencing another vowel
     * @param v
     */
    Vowel(const Vowel &v);

    /**
     * Requires: char that is a Vowel
     * Modifies: None
     * Effects: Sets the Vowel of the piece
     */
    void setCharacter(char characterIn) override;

    /**
     * Requires: None
     * Modifies: Vowel Coordinates
     * Effects: Overrides Piece::movePiece to move vowel piece
     */
    void movePiece() override;

    /**
     * Requires: None
     * Modifies: character
     * Effects: For setting a random vowel character
     */
    char generateVowel();

    /**
     * Creates a square in graphics using the object's X and Y coordinates
     */
    void draw();

protected:
    vector<char> letters = {'a','e','i','o','u','y'}; //list of possible values which are used when generating pieces
    int UNIT1 = 50;
};


#endif //MCJJ_VOWEL_H
