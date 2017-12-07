////
//// Created by Michael Bickley on 11/30/17.
////
//

#include "Letter.h"


#include "Letter.h"

Letter:: Letter() {
    hasPiece = false;
};

Letter::Letter(Piece* p){
    setPiece(p);
    setLetter(p->getCharacter());
    hasPiece = true;
    updatePosition();
}

void Letter::setLetter(char c){
    letter= c;
}

char Letter::getLetter(){
    return letter;
}

void Letter::setPiece(Piece* p){
    Letter::p = p;
    hasPiece = true;
}


void Letter:: updatePosition(){
    if (hasPiece) {
        cout << "Has piece" << endl;
    } else {
        cout << "do not have a piece" << endl;
    }
}