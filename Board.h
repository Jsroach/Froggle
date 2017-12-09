//
// Created by Jacob Jonsson on 2017-11-14.
//

#ifndef MCJJ_BOARD_H
#define MCJJ_BOARD_H

#include <time.h>
#include <string>
#include <vector>
#include <ctime>
#include <iostream>
#include <fstream>
#include "Player.h"
#include "Vowel.h"
#include "Consonant.h"
#include "Vowel.h"

using namespace std;


class Board {
private:
    // Default dimension values
    int boardX = 400;
    int boardY = 400;

    int UNITB = 50;
    vector<char> conLetters = {'B','C','D','F','G','H','J','K','L','M','N','P','Q','R','S','T','V','W','X','Z'};
    vector<char> vowLetters = {'A','E','I','O','U','Y'};
    vector<char> gameWord = {' ',' ',' ',' ',' '};
    vector<char> goalWord = {' ',' ',' ',' ',' '};
    vector<string> words = {"PI   ", "COW  ", "TIME ", "SMILE"};
    int levelCount = 0;
    vector<Consonant> con; // includes both consonants and vowels
    vector<Vowel> vow;
    Player p1 = Player(UNITB*5, UNITB*11);
    bool hasPiece;
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

    void spawnPieces();

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
    vector<Vowel>& getVowel();

    /*
     * Getter
     */
    vector<Consonant>& getConsonant();

    /*
     * Getter
     */
    Player& getPlayer();

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
    void setVowel(Vowel& v);

    /*
     * Setter
     */
    void setConsonant(Consonant& c);

    /*
     * Setter
     */
    void setPlayer(Player& p);

    //Set up for later
    void DrawBoard();

    void wait(int seconds);

    void update();
    //Set up for later
    void checkCollision();

    void setGoalWord(string newWord);

    void displayGoalWord();

    void displayGameWord();

    void generatePieces(string word);

    /**
     * Requires: None
     * Modifies: Board object values
     * Effects: Creates a new game, *starting values of objecs still need to be determined*
     */
    void newGame();

    //Set up for later
    void checkLetter();

    void checkGoal();

    //Set up for later
    void startTimer();

    //Set up for later
    void stopTimer();

    /**
     * Requires: Game to be made
     * Modifies: Output file
     * Effects: Saves the game, can only store one game at a time
     */
    void saveGame();

    /**
     * Requires: Save game to be on file
     * Modifies: Board object values
     * Effects: Loads a saved game into the board
     */
    void loadGame();

    //Set up for later
    void restart();

    void movePieces();

    void drawPieces();

    void movePlayer(int i, int i1);
};

#endif //MCJJ_BOARD_H
