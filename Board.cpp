//
// Created by Jacob Jonsson on 2017-11-15.
//

#include "Board.h"

using namespace std;

Board::Board() = default;

Board::Board(int boardX, int boardY, bool hasPiece, const vector<string> &words)
        : boardX(boardX), boardY(boardY), hasPiece(hasPiece), words(words){}

int Board::getBoardX() const {
    return boardX;
}

int Board::getBoardY() const {
    return boardY;
}

bool Board::isHasPiece() const {
    return hasPiece;
}

const vector<string> &Board::getWords() const {
    return words;
}

clock_t Board::getTime() const {
    return startTime;
}

vector<Vowel> Board::getVowel() const {
    return vow;
}
vector<Consonant> Board::getConsonant() const {
    return con;
}

Player Board::getPlayer() const {
    return player;
}

void Board::setBoardX(int boardX) {
    Board::boardX = boardX;
}

void Board::setBoardY(int boardY) {
    Board::boardY = boardY;
}

void Board::setHasPiece(bool hasPiece) {
    Board::hasPiece = hasPiece;
}

void Board::setWords(const vector<string> &words) {
    Board::words = words;
}

void Board::setTime(clock_t time) {
    Board::startTime = time;
}

void Board::setVowel(Vowel v) {
    vow.emplace_back(v);
}

void Board::setConsonant(Consonant c) {
    con.emplace_back(c);
}

void Board::setPlayer(Player p) {
    player = p;
}

void Board::DrawBoard() {
    // Graphics stuff
}

bool Board::checkLetter() {
    // TODO: Implement
    return false;
}

void Board::startTimer() {
    setTime(clock());
    cout << clock() << endl;
}

void Board::stopTimer() {
    double duration = (clock() - startTime) / (double)CLOCKS_PER_SEC;
    cout << "Number of seconds: " << duration << endl;
}

bool Board::checkCollision() {
    // loop through the vector of all pieces.
    // if piece has the same y value as player, check x value.
    // if the x value for the piece is the same as the x value for the player a collision happened.
    return false;
}

void Board::saveGame() {
    // Should generate ID for each game and use that to find the right file.
    int gameID = 1;
    // string textTitle = "game-" << gameID << ".txt";
    ofstream file("game.txt");
    for (int i = 0; i < vow.size(); ++i) {
        file << "v," << vow[i].getCharacter() << ',' << vow[i].getX() << ',' << vow[i].getY() << ',' << endl;
    }
    for (int i = 0; i < con.size(); ++i) {
        file << "c," << con[i].getCharacter() << ',' << con[i].getX() << ',' << con[i].getY() << ',' << endl;
    }
    if (player.getCharacter() == ' ') {
        file << "p,!," << player.getX() << ',' << player.getY() << ',' << endl;
    } else {
        file << "p," << player.getCharacter() << ',' << player.getX() << ',' << player.getY() << ',' << endl;
    }
    //file << "Writing to file" << endl;
    file.close();
    con.clear();
    vow.clear();
    player = Player(0,0);
}

void Board::loadGame() {
    int gameID = 1;
    char type;
    char character;
    char comma;
    int x;
    int y;

    ifstream file("game.txt");
    while(file) {
        file >> type >> comma >> character >> comma >> x >> comma >> y >> comma;
        if (type == 'v') {
            vow.emplace_back(Vowel(character, x, y));
        }else if (type == 'c') {
            con.emplace_back(Consonant(character, x, y));
        }else if (type == 'p' && character == '!'){
            setPlayer(Player(x,y));
        }else {
            setPlayer(Player(x,y));
            player.setCharacter(character);
        }
    }
    file.close();
}

void Board::newGame() {
    con.clear();
    vow.clear();
    player = Player(0,0);
    con.emplace_back(Consonant(' ', 0 ,0));
    vow.emplace_back(Vowel(' ', 0, 0));
    player = Player(0,0);

    cout << "New Game Started!" << endl;

}
void Board::restart() {
    cout << "Restarting game" << endl;
    // TODO: Implement restart function
    // Loop through all the pieces and generate new positions for them.
    // Reset the players letters to zero.
    // Generate a new word.
}
