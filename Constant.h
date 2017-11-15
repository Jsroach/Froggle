//
// Created by cn345 on 11/15/2017.
//

#ifndef MCJJ_CONSTANT_H
#define MCJJ_CONSTANT_H

#include "Piece.h"

class Constant : public Piece {
private:
    vector<char> cPieces = {'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','z'};

public:
    Constant();

    Constant(char characterIn);

    bool checkPosition() override;
    void setPosition(int x, int y) override;
    void setCharacter(char character) override;
    char getCharacter() override;
    void movePiece() override;

};
#endif //MCJJ_CONSTANT_H
