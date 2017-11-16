#include <iostream>
#include "Board.h"
#include "Player.h"
#include "Vowel.h"
#include "Consonant.h"
#include "Piece.h"

int main() {
//    std::cout << "Hello, World!" << std::endl;

    // Create a board
    Board board = Board();
    // Call board methods
    board.saveGame();
    board.loadGame();
    Player player = Player(200, 500);
    Vowel v1 = Vowel('a', 0, 100);
    Consonant c1 = Consonant('t', 0, 200);

    player.getPosition();
    player.movePiece();
    player.getPosition();

    v1.getPosition();
    v1.movePiece();
    v1.getPosition();

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