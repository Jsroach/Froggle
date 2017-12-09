//
// Created by Michael Bickley on 11/16/17.
//

#include "Player.h"
#include "graphics.h"

Player:: Player() = default;

Player:: Player(int x, int y){
    setX(x);
    setY(y);
    character = ' ';
}

// Sets a new character on the player and then changes the flag setHasLetter to make sure we draw the
// letter on the player.
void Player:: setCharacter(char characterIn) {
    character = characterIn;
    setHasLetter(true);
    drawLetter();
}

void Player:: movePiece(){
    //Moves piece left one SPACE
    setPosition(getX()-SPACE, getY());
}

// Changes the players x and y value on the screen based on the new passed in values.
void Player::movePlayer(int deltaX, int deltaY){
    if (getX()+deltaX <= 500 && getX()+deltaX>=0){
        if(getY()+deltaY<=600 && getY()+deltaY>=0){
            setPosition(getX()+deltaX,getY()+deltaY);
        }
    }
}

// Draws the player on the screen
void Player:: draw() {
        glColor3f(1, 0, 0);
        glBegin(GL_QUADS);
        // top left corner
        glVertex2i(getX()+5, getY()+5);
        // top right corner
        glVertex2i(getX() + 45, getY()+5);
        // bottom right corner
        glVertex2i(getX() + 45, getY() + 45);
        // bottom left corner
        glVertex2i(getX()+5, getY() + 45);

        glEnd();
    drawLetter();
}
