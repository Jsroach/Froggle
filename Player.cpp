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
    setX(x);
    setY(y);
    character = ' ';
}

void Player:: setCharacter(char characterIn) {
    character = characterIn;
}

void Player:: movePiece(){
    setPosition(getX(), getY()-SPACE);
}
