//
// Created by Michael Bickley on 11/30/17.
//

#include "Letter.h"

Letter:: Letter(){}

Letter:: Letter(Piece p){
    //setPiece(p);
    setLetter(p.getCharacter());
    //updatePosition(p.getX(),p.getY());
}

void Letter:: setLetter(char c){
    letter= c;
}

char Letter:: getLetter(){
    return letter;
}

void Letter:: setPiece(Piece p){
    p = p;
}

Piece Letter:: getPiece(){
    return p;
}

void Letter:: updatePosition(){

}