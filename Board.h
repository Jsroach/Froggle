//
// Created by Jacob Jonsson on 2017-11-14.
//

#ifndef MCJJ_BOARD_H
#define MCJJ_BOARD_H

#include <string>
#include <vector>
#include <ctime>
#include <iostream>
#include <fstream>
#include "Player.h"

using namespace std;

class Board {
private:
    // Default dimension values
    int boardX = 400;
    int boardY = 400;

    vector<Piece> pieces; // includes both consonants and vowels
    Player player;
    bool hasPiece;
    vector<string> words;
    clock_t startTime;

public:
    /*
     * Default constructor
     */
    Board();

    /*
     * * Constructor
     */
    Board(int boardX, int boardY, bool hasPiece, const vector<string> &words);

    /*
     * Getter
     */
    int getBoardX() const;

    /*
     * Getter
     */
    int getBoardY() const;

    /*
     * Getter
     */
    bool isHasPiece() const;

    /*
     * Getter
     */
    const vector<string> &getWords() const;

    /*
     * Getter
     */
    clock_t getTime() const;

    /*
     * Setter
     */
    void setBoardX(int boardX);

    /*
     * Setter
     */
    void setBoardY(int boardY);

    /*
     * Setter
     */
    void setHasPiece(bool hasPiece);

    /*
     * Setter
     */
    void setWords(const vector<string> &words);

    /*
     * Setter
     */
    void setTime(clock_t time);

    void DrawBoard();
    bool checkCollision();
    bool checkLetter();
    void startTimer();
    void stopTimer();

    void saveGame();
    void loadGame();
    void restart();
};

#endif //MCJJ_BOARD_H
