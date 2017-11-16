 //
// Created by Jacob Jonsson on 2017-11-15.
//

#include "Board.h"


void Board::DrawBoard() {
    // Use graphics
}

bool Board::checkLetter() {
    return false;
}

void Board::startTimer() {
    time = std::clock();
}

void Board::endTimer() {
    double duration = (std::clock() - time) / (double) CLOCKS_PER_SEC;
    std::cout << "Number of seconds: " << duration << std::endl;
}

Board::Board() = default;

Board::Board(int boardX, int boardY, bool hasPiece, const vector<string> &words, clock_t time)
        : boardX(boardX), boardY(boardY), hasPiece(hasPiece), words(words),
          time(time) {}

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
    return time;
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
    Board::time = time;
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
//     string textTitle = "game-" << gameID << ".txt";
     ofstream file ("game.txt");
     file << "Writing to file" << endl;
     file.close();
 }

 void Board::loadGame() {
     int gameID = 1;
     string line;
     ifstream file ("game.txt");

     if (file.is_open()) {
         while (getline(file, line)) {
             cout << line << endl;
         }
         file.close();
     } else {
         cout << "Unable to open file" << endl;
     }
 }
