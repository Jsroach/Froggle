//
// Created by cn345 on 11/15/2017.
//

#ifndef MCJJ_CONSTANT_H
#define MCJJ_CONSTANT_H

#include "Piece.h"

class Consonant : public Piece {
private:
    //Vector of consonants
    vector<char> cPieces = {'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','z'};
    int UNIT1 = 50;
public:
    /**
     * Requires: None
     * Modifies: None
     * Effects: Default Constructor
     */
    Consonant();

    /**
     * Requires: char that is a consonant
     * Modifies: Piece::character
     * Effects: Creates a consonant with only a character and no coordinates
     */
    Consonant(char characterIn);

    /**
     * Requires: x value, y value
     * Modifies: x,y
     * Effects: Creates a consonant with full coordinates
     */
    Consonant(int xIn, int yIn);

    /**
     * Requires: char that is a consonant, x value, y value
     * Modifies: Piece::character, x,y
     * Effects: Creates a consonant with a character and full coordinates
     */
    Consonant(char characterIn, int xIn, int yIn);


    /**
     * Creates a consonant object by referencing another consonant
     * @param c
     */
    Consonant(const Consonant &c);

    /**
     * Requires: None
     * Modifies: Consonant Coordinates
     * Effects: Overrides Piece::movePiece to move consonant piece
     */
    void movePiece() override;

    /**
     * Requires: char that is a consonant
     * Modifies: None
     * Effects: Sets the consonant of the piece
     */
    void setCharacter (char characterIn) override;

    /**
     * Requires: None
     * Modifies: character
     * Effects: For setting a random consonant character
     */
    char generateConsonant();

    /**
     * Creates a square in graphics using the object's X and Y coordinates
     */
    void draw();

};
#endif //MCJJ_CONSTANT_H
