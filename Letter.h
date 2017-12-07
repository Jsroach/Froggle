////
//// Created by Michael Bickley on 11/30/17.
////
//
#ifndef MCJJ_LETTER_H
#define MCJJ_LETTER_H
#include "Piece.h"

using namespace std;

class Letter : public Piece {
public:
    Letter();

    explicit Letter(Piece* p);

    void setLetter(char c);

    char getLetter();

    void setPiece(Piece* p);

    void updatePosition();

    void updatePosition(int x, int y);

private:
    Piece* p;
    char letter;
    bool hasPiece;
};

#endif //MCJJ_LETTER_H
