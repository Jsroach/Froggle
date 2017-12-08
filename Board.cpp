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
        : boardX(boardX), boardY(boardY), hasPiece(hasPiece), words(words){
}

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

vector<Vowel>& Board::getVowel() {
    return vow;
}
vector<Consonant>& Board::getConsonant() {
    return con;
}

Player& Board::getPlayer() {
    return p1;
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
    p1 = p;
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
    for(int i = 0; i < goalWord.size(); i++){
        glColor3f(1.0, 0.0, 0.0);
        glRasterPos2i(static_cast<GLint>(50 * (3.35 + i)), static_cast<GLint>(50 * 12.7));
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, goalWord[i]);
    }
}

void Board::displayGameWord() {
    for (int i = 0; i < goalWord.size(); i++){
        if (gameWord[i] != ' ' and goalWord[i] == gameWord[i]) {
            glColor3f(0.0, 0.0, 0.0);
            glRasterPos2i(static_cast<GLint>(50 * (3.35 + i)), static_cast<GLint>(50 * 12.7));
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, gameWord[i]);
        }
    }
}

void Board::newGame() {
    con.clear();
    vow.clear();
    goalWord.clear();
    gameWord.clear();

    for (char c : words[0]) {
        goalWord.emplace_back(c);
    }

    for (char c : words.at(0)) {
        for (char v : conLetters) {
            if (c == v) {
                con.emplace_back(c, UNITB*5, UNITB*6);
            }
        }
    }


    for (char c : words.at(0)) {
        for (char v : vowLetters) {
            if (c == v) {
                vow.emplace_back(c, UNITB*5, UNITB*2);
            }
        }
    }

    p1 = Player(UNITB*5,UNITB*11);

    cout << "Done with setting up game" << endl;
}

void Board:: wait(int seconds) {
    clock_t endwait;
    endwait = clock () + seconds * CLOCKS_PER_SEC ;
    while (clock() < endwait) {}
}

void Board:: update(){
    while (start){
        //move cars in vector
        wait(0.1);
    }
}

void Board::checkLetter() {

    if (p1.getY() == (600)){
        for(int i=0 ; i<goalWord.size();i++){
            if(p1.getX()== (50 * (i+3)) && goalWord[i]!= gameWord[i] && p1.getCharacter() == goalWord[i]) {
                gameWord[i]= p1.getCharacter();
                displayGameWord();
                p1.setCharacter(' ');

            }

        }
    }

    int correctCount = 0;

    for(int i = 0 ; i < goalWord.size();i++){
        if(goalWord[i] == gameWord[i]){
            correctCount++;
        }
    }
    if(correctCount == gameWord.size()){
        cout<<"pi spelled"<<endl;
        for (char &i : gameWord) {
            i = ' ';
        }
        levelCount++;
        setGoalWord(words[levelCount]);
        displayGoalWord();
    }
}

void Board::startTimer() {
    startTime = clock();
}

void Board::stopTimer() {
    double duration = (clock() - startTime) / (double)CLOCKS_PER_SEC;
}

void Board::checkCollision() {

    for (auto &i : getConsonant()) {
        if (p1.getX() == i.getX() and p1.getY() == i.getY()) {
            p1.setCharacter(i.getCharacter());
        }
    }

    for (auto &i : getVowel()) {
        if (p1.getX() == i.getX() and p1.getY() == i.getY()) {
            p1.setCharacter(i.getCharacter());
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
    if (p1.getCharacter() == ' ') {
        file << "p,!," << p1.getX() << ',' << p1.getY() << ',' << endl;
    } else { // Else just add character value
        file << "p," << p1.getCharacter() << ',' << p1.getX() << ',' << p1.getY() << ',' << endl;
    }
    //file << "Writing to file" << endl;
    file.close();
    //To demonstrate save worked in testing
    con.clear();
    vow.clear();
    p1 = Player(0,0);
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
            p1.setCharacter(character);
        }
    }
    file.close();
}

void Board::restart() {
    cout << "Restarting game" << endl;
    // TODO: Implement restart function
    // Loop through all the pieces and generate new positions for them.
    // Reset the players letters to zero.
    // Generate a new word.
}

void Board::movePieces() {
    for (auto &i : getConsonant()) {
        i.movePiece();
    }

    for (auto &i : getVowel()) {
        i.movePiece();
    }
}

void Board::spawnPieces() {
//    con.emplace_back('P', 50*5, 50*10);
//    vow.emplace_back('I', 50*2, 50*6);
}

void Board::drawPieces() {
    p1.draw();

    for (auto &i : getConsonant()) {
        if (i.getHasLetter()) {
            i.draw();
        }
    }

    for (auto &i : getVowel()) {
        if (i.getHasLetter()) {
            i.draw();
        }
    }
}

void Board::movePlayer(int i, int i1) {
    p1.movePlayer(i, i1);
}
