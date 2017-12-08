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
#include "Vowel.h"

using namespace std;


class Board {
private:
    // Default dimension values
    int boardX = 400;
    int boardY = 400;

    vector<char> goalWord = {'P', 'I', ' ', ' ', ' '};
    vector<char> gameWord = {' ',' ',' ',' '};
    vector<string> words = {"PI   ", "COW ", "TIME ", "SMILE" };
    int levelCount = 0;
    vector<Consonant> con; // includes both consonants and vowels
    vector<Vowel> vow;
    Player player;
    bool hasPiece;
    clock_t startTime;
    double duration;

public:
    bool start = true;
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
    void checkCollision(int px, int py, Player& player);
    /*
     * Setter
     */
    void setGoalWord(string newWord);
    /**
     * Requires: Nothing
     * Modifies: Nothing
     * Effects: displays the goal word in red at the bottom of the playing field
     */
    void displayGoalWord();
    /**
     * Requires: Nothing
     * Modifies: Nothing
     * Effects: displays the game word (letters that have been placed correctly) in black at the bottom of the playing field
     */
    void displayGameWord();

    //Set up for later
    void checkLetter(int pX, int pY, Player& player);

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

    /**
     * Requires: None
     * Modifies: Board object values
     * Effects: Creates a new game, *starting values of objecs still need to be determined*
     */
    void newGame();

    //Set up for later
    void restart();
};

#endif //MCJJ_BOARD_H
