//
// Created by Michael Bickley on 11/16/17.
//

#ifndef MCJJ_PLAYER_H
#define MCJJ_PLAYER_H
#include "Piece.h"

class Player : public Piece {
public:
    /*
     * Default Constructor
     */
    Player();

    /**
     * Requires: Coordinates
     * Modifies: None
     * Effects: Makes a Player with coordinates but no character (this is the starting character)
     */
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

    /*
     * Requires: a x and y value
     * Modifies: changes the players position
     * Effects: moves the player on the screen
     */
    void movePlayer(int deltaX, int deltaY);

    /*
     * Requires: nothing
     * Modifies: nothing
     * Effects: draws the player object on the screen
     */
    void draw();
};


#endif //MCJJ_PLAYER_H
