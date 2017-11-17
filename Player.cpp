//
// Created by Michael Bickley on 11/16/17.
//

#include "Player.h"
/*
 * default constructor
 */
Player:: Player(){}
//constructor sets initial positions (character is null initially)
/*
 * Requires: position (x and y)
 * Modifies: player object
 * Effects: player object position
 */
Player:: Player(int x, int y){
    setPosition(x,y);
}
/*
 * sets character as parameter
 * Requires: Char character
 * Modifies: Player character field
 * Effects: player object
 **/
void Player:: setCharacter(char characterIn) {
    character = characterIn;
}
/* for now moves player "up" by SPACE
 * Requires: nothing
 * Modifies: player position
 * Effects: player object
 **/

void Player:: movePiece(){
    setPosition(getX(), getY()-SPACE);
}
