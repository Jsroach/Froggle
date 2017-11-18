//
// Created by Michael Bickley on 11/16/17.
//

#ifndef MCJJ_PLAYER_H
#define MCJJ_PLAYER_H
#include "Piece.h"

class Player : public Piece {
public:
    Player();

    Player(int x, int y);
    /*
     * sets character as parameter
     * Requires: Char character
     * Modifies: Player character field
     * Effects: player object
     **/
    void setCharacter(char characterIn) override;

    /* for now moves player "up" by SPACE
     * Requires: nothing
     * Modifies: player position
     * Effects: player object
     **/
    void movePiece() override;
};


#endif //MCJJ_PLAYER_H
