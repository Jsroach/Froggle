#include <iostream>
#include "Board.h"
#include <thread>
#include <cstdlib>
#include "Piece.h"
#include "Consonant.h"

using namespace std::this_thread;
using namespace std::chrono;

int main() {

    // Create a board
    Board board = Board();
    // Write to a text file and load from a text file
    board.saveGame();
    board.loadGame();

    Consonant c1 = Consonant('t', SPACE*20, SPACE);
    c1.getPosition();
    c1.movePiece();
    c1.getPosition();
    return 0;
}