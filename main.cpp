#include <iostream>
#include "Board.h"

int main() {
//    std::cout << "Hello, World!" << std::endl;

    // Create a board
    Board board = Board();
    // Call board methods
    board.saveGame();
    board.loadGame();

    return 0;
}