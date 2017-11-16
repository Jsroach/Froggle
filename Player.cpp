//
// Created by Michael Bickley on 11/16/17.
//

#include "Player.h"
#include "Piece.h"
//default  constructer
Player:: Player(){}
//construtor sets initial positions (character is null initially)
Player:: Player(int x, int y){
    setPosition(x,y);
}
//sets character as parameter
void Player:: setCharacter(char characterIn) {
    character = characterIn;
}
//for now moves player "up" by SPACE
void Player:: movePiece(){
    setPosition(getX(), getY()-SPACE);
}
