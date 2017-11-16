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
using namespace std;

class Board {
private:
    int boardX;
    int boardY;
    // vector<Piece> pieces; // includes both consonant and vowels
    // Player player;
    bool hasPiece;
    vector<string> words;
    std::clock_t time;

public:
    /*
     * Default constructor
     */
    Board();

    /*
     * * Constructor
     */
    Board(int boardX, int boardY, bool hasPiece, const vector<string> &words, clock_t time);

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
    void endTimer();

    void saveGame();
    void loadGame();
};

#endif //MCJJ_BOARD_H
