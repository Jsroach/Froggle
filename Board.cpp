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
    levelCount = 0;

    for (int i = 0; i < gameWord.size(); ++i) {
        gameWord[i] = ' ';
    }

    for (char c : words[0]) {
        goalWord.emplace_back(c);
    }

    spawnPieces();

    p1 = Player(UNITB*5,UNITB*11);
    cout << "Done with setting up game" << endl;


}

void Board::generatePieces(string word) {
    con.clear();
    vow.clear();
    for (char c : word) {
        for (char v : conLetters) {
            if (c == v) {
                //con.emplace_back(c, UNITB*5, UNITB*6);
                con.emplace_back(c, UNITB*5, UNITB*6);
                con.emplace_back(c, UNITB*5, UNITB*5);
            }
        }
    }

    cout << con.size() << endl;

    for (char c : word) {
        for (char v : vowLetters) {
            if (c == v) {
                vow.emplace_back(c, UNITB*5, UNITB*2);
            }
        }
    }
}

void Board:: wait(int seconds) {
    clock_t endwait;
    endwait = clock () + seconds * CLOCKS_PER_SEC ;
    while (clock() < endwait) {}
}

void Board:: update(){
    while (start){
        //move cars in vector
        wait(static_cast<int>(0.1));
    }
}

void Board::checkLetter() {

    if (p1.getY() == (600)) {
        for (int i = 0; i < goalWord.size(); i++) {
            if (p1.getX() == (50 * (i + 3)) && goalWord[i] != gameWord[i] && p1.getCharacter() == goalWord[i]) {
                gameWord[i] = p1.getCharacter();
                displayGameWord();
                p1.setCharacter(' ');

            }

        }
    }

    int correctCount = 0;

    for (int i = 0; i < goalWord.size(); i++) {
        if (goalWord[i] == gameWord[i]) {
            correctCount++;
        }
    }

    cout << correctCount << endl;

    if (correctCount == goalWord.size()) {
        cout << "pi spelled" << endl;
        for (char &i : gameWord) {
            i = ' ';
        }
        levelCount++;
        setGoalWord(words[levelCount]);
        //generatePieces(words[levelCount]);
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
    //write to file
    ofstream file("gameobjects.txt");
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

    ofstream stat("gamestats.txt");
    for (auto &i : goalWord) {
        stat << "g," <<  goalWord[i] << ',';
    }
    stat << endl;

    for (auto &i : gameWord) {
        char ch = gameWord[i];
        stat << "w," << ch << ',';
    }
    stat << endl;

    stat.close();
    //To demonstrate save worked in testing
    con.clear();
    vow.clear();
    p1 = Player(UNITB*5,UNITB*11);
}

void Board::loadGame() {
    //Define variables
    char type;
    char character;
    char comma;
    int x;
    int y;

    //Open save file
    ifstream file("gameobjects.txt");
    while(file) {
        //Get information from each line
        file >> type >> comma >> character >> comma >> x >> comma >> y >> comma;
        //V = vowel
        if (type == 'v') {
            vow.emplace_back(character, x, y);
        }else if (type == 'c') {
            con.emplace_back(character, x, y);
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

    ifstream stat("gamestat.txt");
    while (stat) {
        char type;
        char comma;
        char ch1;
        char ch2;
        char ch3;
        char ch4;
        char ch5;

        stat >> type >> comma >> ch1 >> comma >> ch2 >> comma >> ch3 >> comma >> ch4 >> comma >> ch5 >> comma;

        if (type == 'g') {
            goalWord.emplace_back(ch1);
            goalWord.emplace_back(ch2);
            goalWord.emplace_back(ch3);
            goalWord.emplace_back(ch4);
            goalWord.emplace_back(ch5);
        }else if (type == 'w') {
            gameWord.emplace_back(ch1);
            gameWord.emplace_back(ch2);
            gameWord.emplace_back(ch3);
            gameWord.emplace_back(ch4);
            gameWord.emplace_back(ch5);

        }

    }
    stat.close();

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
    con.emplace_back('P', 50, 50*10);
    con.emplace_back('C', 50, 50*8);
    con.emplace_back('L', 50*11, 50*6);
    con.emplace_back('M', 50, 50*6);
    con.emplace_back('S', 50*11, 50*5);
    con.emplace_back('W', 50, 50*5);
    con.emplace_back('T', 50*11, 50*4);

    vow.emplace_back('I', 50*11, 50*2);
    vow.emplace_back('E', 50, 50*2);
    vow.emplace_back('O', 50*11, 50*1);
}

void Board::drawPieces() {
    p1.draw();

    for (auto &i : con) {
        if (i.getHasLetter()) {
            i.draw();
        }
    }

    for (auto &i : vow) {
        if (i.getHasLetter()) {
            i.draw();
        }
    }
}

void Board::movePlayer(int i, int i1) {
    p1.movePlayer(i, i1);
}
