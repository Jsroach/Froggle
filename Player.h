//
// Created by Michael Bickley on 11/16/17.
//

#ifndef MCJJ_PLAYER_H
#define MCJJ_PLAYER_H


class Player : public Piece {
public:
    Player();

    Player(int x, int y);

    void set_character(char character) override;

private:
    void movePiece() override;
};


#endif //MCJJ_PLAYER_H
