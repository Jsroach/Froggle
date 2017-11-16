#include <iostream>
#include "Board.h"

int main() {
//    std::cout << "Hello, World!" << std::endl;

    Board board = Board();

    board.saveGame();
    board.loadGame();

    return 0;
}