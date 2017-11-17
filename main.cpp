#include <iostream>
#include "Board.h"
#include <thread>
#include <cstdlib>
#include "Consonant.h"
#include "Player.h"
#include "Vowel.h"
#include "Piece.h"

using namespace std::chrono;


int main() {

    // Create a board
    Board board = Board();
    // Write to a text file and load from a text file
    board.saveGame();
    board.loadGame();
    Player player = Player(200, 500);
    Vowel v1 = Vowel('a', 0, 100);
    Consonant c1 = Consonant('t', 200, 10);

    cout << "Player: " << endl;
    player.getPosition();
    player.movePiece();
    player.getPosition();

    cout << "Vowel: " << endl;
    v1.getPosition();
    v1.movePiece();
    v1.getPosition();

    cout << "Consonant: " << endl;
    c1.getPosition();
    c1.movePiece();
    c1.getPosition();

    char pC = player.getCharacter();
    cout<<pC<<endl;
    player.setCharacter('r');
    pC = player.getCharacter();
    cout<<pC<<endl;

    char vC = v1.getCharacter();
    cout<<vC<<endl;
    v1.setCharacter('o');
    vC = v1.getCharacter();
    cout<<vC<<endl;

    char cC = c1.getCharacter();
    cout<<cC<<endl;
    c1.setCharacter('p');
    cC = c1.getCharacter();
    cout<<cC<<endl;

    return 0;
}