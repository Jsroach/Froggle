#include <iostream>
#include "Board.h"
#include <thread>
#include <cstdlib>
#include "Consonant.h"
#include "Player.h"
#include "Vowel.h"
#include "Piece.h"

#include <type_traits>

#include "graphics.h"
#include "Letter.h"

using namespace std::chrono;

int main(int argc, char** argv) {
    /**
    //Create Objects
    Player player1 = Player(200, 500);
    Vowel v1 = Vowel('a', 0, 100);
    Consonant c1 = Consonant('t', 200, 10);
    Board board = Board();

    //Put Objects on board
    board.setVowel(v1);
    board.setConsonant(c1);
    board.setPlayer(player1);

    //Show board object values before saving (should be equal to above)
    cout << "Before Save: " << endl;
    //prints out consonant
    for (int i = 0; i < board.getConsonant().size(); i++) {
        vector<Consonant> con = board.getConsonant();
        cout << "Consonant(" << con[i].getCharacter() << ", " << con[i].getX() << ", " << con[i].getY() << ')' << endl;
    }
    //prints out vowels
    for (int i = 0; i < board.getVowel().size(); i++) {
        vector<Vowel> vow = board.getVowel();
        cout << "Vowel(" << vow[i].getCharacter() << ", " << vow[i].getX() << ", " << vow[i].getY() << ')' << endl;
    }
    //Prints out players
    cout << "Player(" << board.getPlayer().getCharacter() << ", " << board.getPlayer().getX() << ", " << board.getPlayer().getY() << ')' << endl;
    cout << " " << endl;

    // Save Game
    board.saveGame();

    //Show board values after save (Consonant and Vowel vectors cleared and player at 0,0)
    cout << "After Save: " << endl;
    for (int i = 0; i < board.getConsonant().size(); i++) {
        vector<Consonant> con = board.getConsonant();
        cout << "Consonant(" << con[i].getCharacter() << ", " << con[i].getX() << ", " << con[i].getY() << ')' << endl;
    }
    for (int i = 0; i < board.getVowel().size(); i++) {
        vector<Vowel> vow = board.getVowel();
        cout << "Vowel(" << vow[i].getCharacter() << ", " << vow[i].getX() << ", " << vow[i].getY() << ')' << endl;
    }
    cout << "Player(" << board.getPlayer().getCharacter() << ", " << board.getPlayer().getX() << ", " << board.getPlayer().getY() << ')' << endl;
    cout << " " << endl;

    //Load game
    board.loadGame();

    //Shows board values after loading game (SHould be back to values before save)
    cout << "After Load: " << endl;
    for (int i = 0; i < board.getConsonant().size(); i++) {
        vector<Consonant> con = board.getConsonant();
        cout << "Consonant(" << con[i].getCharacter() << ", " << con[i].getX() << ", " << con[i].getY() << ')' << endl;
    }
    for (int i = 0; i < board.getVowel().size(); i++) {
        vector<Vowel> vow = board.getVowel();
        cout << "Vowel(" << vow[i].getCharacter() << ", " << vow[i].getX() << ", " << vow[i].getY() << ')' << endl;
    }
    cout << "Player(" << board.getPlayer().getCharacter() << ", " << board.getPlayer().getX() << ", " << board.getPlayer().getY() << ')' << endl;
    cout << " " << endl;

    //make new game
    board.newGame();

    //Actual coordinates to be determined but should reset everything to either blank or 0
    cout << "After New Game: " << endl;
    for (int i = 0; i < board.getConsonant().size(); i++) {
        vector<Consonant> con = board.getConsonant();
        cout << "Consonant(" << con[i].getCharacter() << ", " << con[i].getX() << ", " << con[i].getY() << ')' << endl;
    }
    for (int i = 0; i < board.getVowel().size(); i++) {
        vector<Vowel> vow = board.getVowel();
        cout << "Vowel(" << vow[i].getCharacter() << ", " << vow[i].getX() << ", " << vow[i].getY() << ')' << endl;
    }
    cout << "Player(" << board.getPlayer().getCharacter() << ", " << board.getPlayer().getX() << ", " << board.getPlayer().getY() << ')' << endl;
    cout << " " << endl;

    //Shows movement of player
    cout << "Player Movement: " << endl;
    player1.getPosition();
    player1.movePiece();
    player1.getPosition();
    cout << " " << endl;

    //Shows movement of Vowel
    cout << "Vowel Movement: " << endl;
    v1.getPosition();
    v1.movePiece();
    v1.getPosition();
    cout << " " << endl;

    //Shows movement of consonant
    cout << "Consonant Movement: " << endl;
    c1.getPosition();
    c1.movePiece();
    c1.getPosition();
    cout << " " << endl;

    //Changes players character
    cout<< "Player's Character Change: "<<endl;
    cout << player1.getCharacter() << endl; //Should be blank
    player1.setCharacter('r');
    cout << player1.getCharacter() << endl;

    //Changes Vowels character
    cout<< "Vowel's Character Change: "<<endl;
    cout << v1.getCharacter() << endl; //a
    v1.setCharacter('t');
    cout << v1.getCharacter() << endl;//Character is not a vowel
    v1.setCharacter('o');
    cout << v1.getCharacter() << endl; //o

    //Changes Consonants character
    cout<< "Consonant's Character Change: "<<endl;
    cout << c1.getCharacter() << endl; //t
    c1.setCharacter('o');
    cout << c1.getCharacter() << endl;//Character is not a consonant
    c1.setCharacter('s');
    cout << c1.getCharacter() << endl; //s

    **/

//    Consonant consonant = Consonant();
//    consonant.setX(10);
//
//
//    Letter l = Letter();
//    l.updatePosition();
//    l.setPiece(&consonant);
//    l.updatePosition();


    graphicsPlay(argc, argv);


    return 0;
}