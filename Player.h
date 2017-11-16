//
// Created by Michael Bickley on 11/16/17.
//

#ifndef MCJJ_PLAYER_H
#define MCJJ_PLAYER_H
#include "Piece.h"

class Player : public Piece {
public:
    Player();

    Player(int x, int y);

    void setCharacter(char characterIn) override;

    void movePiece() override;
};


#endif //MCJJ_PLAYER_H
