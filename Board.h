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
#include "Vowel.h"
#include "Consonant.h"

using namespace std;

class Board {
private:
    // Default dimension values
    int boardX = 400;
    int boardY = 400;

    vector<Consonant> con; // includes both consonants and vowels
    vector<Vowel> vow;
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
     * Getter
     */
    vector<Vowel> getVowel() const;

    /*
     * Getter
     */
    vector<Consonant> getConsonant() const;

    /*
     * Getter
     */
    Player getPlayer() const;

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

    /*
     * Setter
     */
    void setVowel(Vowel v);

    /*
     * Setter
     */
    void setConsonant(Consonant c);

    /*
     * Setter
     */
    void setPlayer(Player p);

    void DrawBoard();
    bool checkCollision();
    bool checkLetter();
    void startTimer();
    void stopTimer();

    void saveGame();
    void loadGame();
    void newGame();
    void restart();
};

#endif //MCJJ_BOARD_H
