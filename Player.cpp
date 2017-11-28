//
// Created by Michael Bickley on 11/16/17.
//

#include "Player.h"

Player:: Player(){}

Player:: Player(int x, int y){
    setX(x);
    setY(y);
    character = ' ';
}

void Player:: setCharacter(char characterIn) {
    character = characterIn;
}

void Player:: movePiece(){
    //Moves piece left one SPACE
    setPosition(getX(), getY()-SPACE);
}
