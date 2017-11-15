//
// Created by Jacob Jonsson on 2017-11-15.
//

#include <ctime>
#include <iostream>
#include "Board.h"


void Board::DrawBoard() {
    // Use graphics
}

bool Board::checkLetter() {
    return false;
}

void Board::startTimer() {
    time = std::clock();
}

void Board::endTimer() {
    double duration = (std::clock() - time) / (double) CLOCKS_PER_SEC;
    std::cout << "Number of seconds: " << duration << std::endl;
}
