//
// Created by cn345 on 11/15/2017.
//

#ifndef MCJJ_CONSTANT_H
#define MCJJ_CONSTANT_H

#include "Piece.h"

class Consonant : public Piece {
private:
    vector<char> cPieces = {'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','z'};

public:
    Consonant();

    Consonant(char characterIn);

    Consonant(char characterIn, int xIn, int yIn);

    void movePiece() override;
    void setCharacter (char characterIn) override;
    char generateConsonant();

};
#endif //MCJJ_CONSTANT_H
