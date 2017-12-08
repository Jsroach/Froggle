//
// Created by Jacob Jonsson on 2017-11-15.
//

#include "Board.h"

#include <utility>
#include "graphics.h"
#include <ctime>

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

void Board::setVowel(Vowel& v) {
    vow.emplace_back(v);
}

void Board::setConsonant(Consonant& c) {
    con.emplace_back(c);
}

void Board::setPlayer(Player& p) {
    player = p;
}

void Board::DrawBoard() {
    // Graphics stuff
}

void Board::setGoalWord(string newWord) {

    for ( int i = 0 ; i < newWord.length(); i++)
    {
        goalWord[i]= newWord[i];
    }
}

void Board::displayGoalWord() {
    for(int i = 0; i<goalWord.size(); i++){
        char goal = goalWord[i];
        glColor3f(1.0, 0.0, 0.0);
        glRasterPos2i(50 * (3.35 + i), 50 * 12.7);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, goalWord[i]);
    }
}

void Board::displayGameWord() {
    for(int i = 0; i<gameWord.size(); i++){
        char goal = gameWord[i];
        glColor3f(0.0, 0.0, 0.0);
        glRasterPos2i(50 * (3.35 + i), 50 * 12.7);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, gameWord[i]);
    }
}
void Board:: wait(int seconds) {
    clock_t endwait;
    endwait = clock () + seconds * CLOCKS_PER_SEC ;
    while (clock() < endwait) {}
}
void Board:: update(){
    while (start == true){
        //move cars in vector
        wait(0.1);
    }
}

void Board::checkLetter(int pX, int pY, Player& player) {
   if (pY == (50 * 12)){
        if(pX== (50 * 3) && goalWord[0]!= gameWord[0] && player.getCharacter() == goalWord[0]) {
                gameWord[0]= player.getCharacter();
                displayGameWord();
                player.setCharacter(' ');

        }
        if(pX== (50 * 4) && goalWord[1]!= gameWord[1] && player.getCharacter() == goalWord[1]) {

                gameWord[1]= player.getCharacter();
                displayGameWord();
                player.setCharacter(' ');


        }
        if(pX== (50 * 5) && goalWord[2]!= gameWord[2] && player.getCharacter() == goalWord[2]) {

                gameWord[2]= player.getCharacter();
                displayGameWord();
                player.setCharacter(' ');

        }
        if(pX== (50 * 6) && goalWord[3]!= gameWord[3] && player.getCharacter() == goalWord[3]) {

                gameWord[3]= player.getCharacter();
                displayGameWord();
                player.setCharacter(' ');

        }
        if(pX== (50 * 7) && goalWord[4]!= gameWord[4] && player.getCharacter() == goalWord[4]) {

                gameWord[4]= player.getCharacter();
                displayGameWord();
                player.setCharacter(' ');


        }



        }
    }



void Board::startTimer() {
    startTime = clock();
}

void Board::stopTimer() {
    double duration = (clock() - startTime) / (double)CLOCKS_PER_SEC;
    cout << "Number of seconds: " << duration << endl;

}

void Board::checkCollision(int pX, int pY, Player& player) {
    // loop through the vector of all pieces.
    // if piece has the same y value as player, check x value.
    // if the x value for the piece is the same as the x value for the player a collision happened.
    for (Consonant c : getConsonant()) {
        if (pX == c.getX() and pY == c.getY()) {
            //cout << "COLLLLL C" << endl;
            player.setCharacter(c.getCharacter());
        }
    }

    for (Vowel v : getVowel()) {
        if (pX == v.getX() and pY == v.getY()) {
            //cout << "COLLLLL V" << endl;
            player.setCharacter(v.getCharacter());
        }
    }
}

void Board::saveGame() {
    // Should generate ID for each game and use that to find the right file.
    int gameID = 1;
    //write to file
    ofstream file("game.txt");
    //Write values of vowel vector to file
    for (auto &i : vow) {
        //Leter is added at beginning to help with loading game in
        file << "v," << i.getCharacter() << ',' << i.getX() << ',' << i.getY() << ',' << endl;
    }
    //Write values of consonant vector to file
    for (auto &i : con) {
        file << "c," << i.getCharacter() << ',' << i.getX() << ',' << i.getY() << ',' << endl;
    }
    //If players character is blank write to file with temporary character
    if (player.getCharacter() == ' ') {
        file << "p,!," << player.getX() << ',' << player.getY() << ',' << endl;
    } else { // Else just add character value
        file << "p," << player.getCharacter() << ',' << player.getX() << ',' << player.getY() << ',' << endl;
    }
    //file << "Writing to file" << endl;
    file.close();
    //To demonstrate save worked in testing
    con.clear();
    vow.clear();
    player = Player(0,0);
}

void Board::loadGame() {
    //Define variables
    int gameID = 1;
    char type;
    char character;
    char comma;
    int x;
    int y;

    //Open save file
    ifstream file("game.txt");
    while(file) {
        //Get information from each line
        file >> type >> comma >> character >> comma >> x >> comma >> y >> comma;
        //V = vowel
        if (type == 'v') {
            vow.emplace_back(Vowel(character, x, y));
        }else if (type == 'c') {
            con.emplace_back(Consonant(character, x, y));
        }else if (type == 'p' && character == '!'){ //Check to see if player character is a filler character
            Player p = Player(x, y);
            setPlayer(p);
        }else {
            Player p = Player(x, y);
            setPlayer(p);
            player.setCharacter(character);
        }
    }
    file.close();
}

void Board::newGame() {
    //Clears all values
    con.clear();
    vow.clear();
    player = Player(0,0);

    //Set needed objects up (values are for testing purposes)
    con.emplace_back(Consonant(' ', 0 ,0));
    vow.emplace_back(Vowel(' ', 0, 0));
    player = Player(0,0);

    //For testing
    cout << "New Game Started!" << endl;

}
void Board::restart() {
    cout << "Restarting game" << endl;
    // TODO: Implement restart function
    // Loop through all the pieces and generate new positions for them.
    // Reset the players letters to zero.
    // Generate a new word.
}
