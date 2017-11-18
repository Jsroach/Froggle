#include <iostream>
#include "Board.h"
#include <thread>
#include <cstdlib>

using namespace std::this_thread;
using namespace std::chrono;

int main() {
    // Create a board
    Board board = Board();
    // Write to a text file and load from a text file
    board.saveGame();
    board.loadGame();

    return 0;
}