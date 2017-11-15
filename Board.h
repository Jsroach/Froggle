//
// Created by Jacob Jonsson on 2017-11-14.
//

#ifndef MCJJ_BOARD_H
#define MCJJ_BOARD_H

class Board {
private:
    int boardX;
    int boardY;
    int pieceX;
    int pieceY;
    bool hasPiece;
    std::clock_t time;

public:
    void DrawBoard();
    bool checkLetter();
    void startTimer();
    void endTimer();
};

#endif //MCJJ_BOARD_H
