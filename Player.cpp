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
    setPosition(getX()-SPACE, getY());
}
/*
void Player:: movePlayer(int deltaX, int deltaY){
    if (getX()+deltaX <= 550 && getX()+deltaX>=0){
        if(getY()+deltaY<=650 && getY()+deltaY>=0){
            setPosition(getX()+deltaX,getY()+deltaY);
        }
    }
}
*/

