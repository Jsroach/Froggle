//
// Created by Michael Bickley on 11/30/17.
//

#ifndef MCJJ_LETTER_H
#define MCJJ_LETTER_H
#include "Piece.h"

<<<<<<< Updated upstream
using namespace std;

=======
>>>>>>> Stashed changes
class Letter {
public:
    Letter();

    Letter(Piece p);

    void setLetter(char c);

    char getLetter();

    void setPiece(Piece p);

    Piece getPiece();

    void updatePosition();
private:
    Piece p;
    char letter;


};


#endif //MCJJ_LETTER_H
