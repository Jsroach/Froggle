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
    file << "Writing to file" << endl;
    file.close();
}

void Board::loadGame() {
    int gameID = 1;
    string line;
    ifstream file("game.txt");

    if (file.is_open()) {
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cout << "Unable to open file" << endl;
    }
}

void Board::restart() {
    cout << "Restarting game" << endl;
    // TODO: Implement restart function
    // Loop through all the pieces and generate new positions for them.
    // Reset the players letters to zero.
    // Generate a new word.
}
