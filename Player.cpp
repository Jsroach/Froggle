//
// Created by Michael Bickley on 11/16/17.
//

#include "Player.h"
#include "graphics.h"

Player:: Player(){
}

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

void Player:: movePlayer(int deltaX, int deltaY){
    if (getX()+deltaX <= 500 && getX()+deltaX>=0){
        if(getY()+deltaY<=650 && getY()+deltaY>=0){
            setPosition(getX()+deltaX,getY()+deltaY);
        }
    }
}



void Player:: draw() {
    glColor3f(1, 0, 0);
    glBegin(GL_QUADS);
    // top left corner
    glVertex2i(getX(), getY());
    // top right corner
    glVertex2i(getX() + 50, getY());
    // bottom right corner
    glVertex2i(getX() + 50, getY() + 50);
    // bottom left corner
    glVertex2i(getX(), getY() + 50);
    glEnd();
}

